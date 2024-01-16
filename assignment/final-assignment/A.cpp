/*设计一个程序实现两个任意长的整数（包括正数和负数）、任意精度实数的加减运算，其中以“-”号开头的为负数。
输入
第一行为一个数字n，表示待计算的组数
接下来为3n行内容，每组内容有3行，第一行表示做加法还是减法，第二三行为两个数字，每次取一组内容来计算。
输出
共有n行，每行要换行。
样例输入 Copy
2
+
1,111,111,111,111,111,111,111,111,111,111,111,111
222,222,222,222,222,222,222,222,222,222,222,222
+
-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765
样例输出 Copy
1,333,333,333,333,333,333,333,333,333,333,333,333
86,419,753,297,530,864,308,641,975,409,753,086,519,864,197,630,875

样例输入 Copy
2
-
1,111,111,111,111,111,111,111,111,111,111,111,111
222,222,222,222,222,222,222,222,222,222,222,222
-
-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765
*/

// 首先是面向过程的解法
#include <bits/stdc++.h>
using namespace std;

int sets = 0;

// 去掉符号位 
string removeSign(string& num) {
    if (num[0] == '-') {
        num.erase(0, 1);
    }
    return num;
}

// 实现大数的加法
string longIntAdd(string& s1, string& s2) {
    string res;
    int carry = 0;
    int index1 = s1.size() - 1;
    int index2 = s2.size() - 1;
    while (index1 >= 0 || index2 >= 0 || carry) {
        int sum = carry;
        if (index1 > -1) {
            sum += s1[index1] - '0';
            index1--;
        }
        if (index2 > -1) {
            sum += s2[index2] - '0';
            index2--;
        }
        carry = sum / 10;
        sum = sum % 10;
        res += to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}

// 实现大数的减法
string subtract(string& num1, string& num2) {
    // 检查是否需要递归调用
    if (num1 < num2) {
        string res = subtract(num2, num1); // 递归调用
        if (res != "0") { // 避免在结果为0时添加负号
            res = '-' + res;
        }
        return res;
    }
    // 正常的减法操作
    string res;
    int carry = 0, n;
    int idx1 = num1.size() - 1, idx2 = num2.size() - 1;

    while (idx1 >= 0 || idx2 >= 0) {
        n = 0;
        if (idx1 >= 0) {
            n = num1[idx1] - '0' - carry;
            idx1--;
        }
        if (idx2 >= 0) {
            n -= (num2[idx2] - '0');
            idx2--;
        }

        if (n < 0) {
            n += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res.push_back(n + '0');
    }

    // 移除前导零
    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
}

// 检查字符串是否表示负数
bool isNegative(string num) {
    return !num.empty() && num[0] == '-';
}

string computeResult(char operation, string num1, string num2) {
    bool neg1 = isNegative(num1);
    bool neg2 = isNegative(num2);

    if (neg1) removeSign(num1);
    if (neg2) removeSign(num2);

    string result;
    if (operation == '+') {
        if (neg1 == neg2) { // 同号相加
            result = longIntAdd(num1, num2);
            if (neg1) result = '-' + result;
        } else { // 异号相加
            result = (neg1 ? subtract(num2, num1) : subtract(num1, num2));
        }
    } else if (operation == '-') {
        if (neg1 == neg2) { // 同号相减
            result = (neg1 ? subtract(num2, num1) : subtract(num1, num2));
        } else { // 异号相减
            result = longIntAdd(num1, num2);
            if (neg1) result = '-' + result;
        }
    }

    return result;
}

int main() {
    while (cin >> sets) {
        while (sets--) {
            char operation;
            string num1, num2;
            cin >> operation >> num1 >> num2;
            for (int i = 0; i < num1.size(); i++) {
                if (num1[i] == ',') {
                    num1.erase(i, 1);
                    i--;
                }
            }
            for (int i = 0; i < num2.size(); i++) {
                if (num2[i] == ',') {
                    num2.erase(i, 1);
                    i--;
                }
            }
            string result = "";
            result = computeResult(operation, num1, num2);
            // 加逗号
            int len = result.size();
            for (int i = len - 3; i > 1; i -= 3) {
                result.insert(i, ",");
            }
            cout << result << endl;
        }
    }
}

//int main() {
    //string num1 = "1111111111111111111111111111111111111";
    //string num2 = "222222222222222222222222222222222222";
    //cout << longIntAdd(num1, num2) << endl;
    //string num3 = "12345678901234567890123456789012345678901234567890";
    //string num4 = "98765432198765432198765432198765432198765432198765";
    //cout << subtract(num3, num4) << endl;
//}