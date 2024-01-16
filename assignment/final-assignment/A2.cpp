/*样例输入 Copy
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
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765*/

// 初具雏形的面向对象解法
#include <bits/stdc++.h>
using namespace std;

struct LongInteger {
    string value;  // 存储长整数的字符串表示
    bool isNegative;  // 表示长整数是否为负

    // 构造函数
    LongInteger(string val) {
        removeComma(val);
        if (val[0] == '-') {
            isNegative = true;
            value = val.substr(1);
        } else {
            isNegative = false;
            value = val;
        }
    }

    // 转换回字符串表示
    string toString() const {
        string result = value;

        int len = result.size();
        for (int i = len - 3; i > 0; i -= 3) {
            result.insert(i, ",");
        }
        return isNegative ? "-" + result: result;
    }
private:
    // 移除字符串表示中的逗号
    void removeComma(string& value) {
        int len = value.size();
        for (int i = 0; i < len; i++) {
            if (value[i] == ',') {
                value.erase(i, 1);
                i--;
            }
        }
    }
};

string add(const LongInteger& num1, const LongInteger& num2) {
    // 实现加法逻辑
    string res;
    int carry = 0;
    int index1 = num1.value.size() - 1;
    int index2 = num2.value.size() - 1;
    while (index1 >= 0 || index2 >= 0 || carry) {
        int sum = carry;
        if (index1 > -1) {
            sum += num1.value[index1] - '0';
            index1--;
        }
        if (index2 > -1) {
            sum += num2.value[index2] - '0';
            index2--;
        }
        carry = sum / 10;
        sum = sum % 10;
        res += to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}

string subtract(const LongInteger num1, const LongInteger num2) {
    // 实现减法逻辑
    if (num1.value < num2.value) {
        string res = subtract(num2, num1); // 递归调用
        if (res != "0") { // 避免在结果为0时添加负号
            res = '-' + res;
        }
        return res;
    }
    // 正常的减法操作
    string res;
    int carry = 0, digit;
    int idx1 = num1.value.size() - 1, idx2 = num2.value.size() - 1;

    while (idx1 >= 0 || idx2 >= 0) {
        digit = 0;
        if (idx1 >= 0) {
            digit = num1.value[idx1] - '0' - carry;
            idx1--;
        }
        if (idx2 >= 0) {
            digit -= (num2.value[idx2] - '0');
            idx2--;
        }

        if (digit < 0) {
            digit += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res += to_string(digit);
    }

    while (res.size() > 1 && res.back() == '0') {
        res.pop_back();
    }
    reverse(res.begin(), res.end());
    return res;
};

int sets = 0;

int main() {
    while (cin >> sets) {
        string num1, num2;
        char operation;
        while (sets--) {
            cin >> operation >> num1 >> num2;
            LongInteger longNum1(num1), longNum2(num2);
            string result;
            
            if (operation == '+') {
                if (longNum1.isNegative == longNum2.isNegative) {
                    result = add(longNum1, longNum2);
                    if (longNum1.isNegative) result = '-' + result;
                } else {
                    result = longNum1.isNegative ? subtract(longNum2, longNum1) : subtract(longNum1, longNum2);
                }
            } else if (operation == '-') {
                if (longNum1.isNegative == longNum2.isNegative) {
                    result = longNum1.isNegative ? subtract(longNum2, longNum1) : subtract(longNum1, longNum2);
                } else {
                    result = add(longNum1, longNum2);
                    if (longNum1.isNegative) result = '-' + result;
                }
            }
            LongInteger longResult(result);
            cout << longResult.toString() << endl;
        }
    }
    return 0;
}