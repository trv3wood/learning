/*设计一个程序实现两个任意长的数（包括正数和负数）、任意精度实数的加减运算，其中以“-”号开头的为负数。

输入
第一行为一个数字n，表示待计算的组数

接下来为3n行内容，每组内容有3行，第一行表示做加法还是减法，第二三行为两个数字，每次取一组内容来计算。

输出
共有n行，每行要换行,小数末尾不保留0,若小数点后都为0则不要小数点。

样例输入 Copy
6
+
1,111,111,111,111,111,111,111,111,111,111,111,111
222,222,222,222,222,222,222,222,222,222,222,222
+
-12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765
+
3.14159265358979384626
6.66666666666666666666666
-
-41,829,471,284,124,414.49104801248981284
-64,580,569,452,374,277.12783183148912947
-
0
0
+
0
0

样例输出 Copy
1,333,333,333,333,333,333,333,333,333,333,333,333
86,419,753,297,530,864,308,641,975,409,753,086,519,864,197,630,875
9.80825932025646051292666
22,751,098,168,249,862.63678381899931663
0
0

额外的测试用例
Test Case 1:
Input:
Copy code
2
+
123456789123456789123456789
987654321987654321987654321
-
987654321987654321987654321
123456789123456789123456789
Output:
1,111,111,111,111,111,111,111,111,111,111,111,111
864,197,532,864,197,532,864,197,532

Test Case 2:
Input:
Copy code
2
+
-0.0000000000000000000000000001
0.0000000000000000000000000001
-
3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274
Output:
0
0.423310825130748003102355911927240386439921701675146245008977564931539776932661501251652347867

Test Case 3:
Input:
Copy code
2
+
-999999999999999999999999999999999999999
1000000000000000000000000000000000000000
-
-0.0000000000000000000000000001
-0.0000000000000000000000000001
Output:
1
0
*/

// 面向对象解法
#include <bits/stdc++.h>
using namespace std;

class DecimalNumber {
public:
    string integerPart;
    string decimalPart;
    bool isNegative;

    // 解析数字，分离整数部分和小数部分
    DecimalNumber(string num) {
        integerPart = "0";
        decimalPart = "0";
        isNegative = false;
        if (num[0] == '-') {
            isNegative = true;
            num.erase(0, 1);
        }
        for (int i = num.size() - 1; i > 0; i--) {
            if (num[i] == '.') {
                decimalPart = num.substr(i + 1);
                integerPart = num.substr(0, i);
                removeComma();
                return;
            }
        }
        integerPart = num;
        removeComma();
    }

    // 重载运算符 +
    DecimalNumber operator+(DecimalNumber& other) {
        string res = "";
        // 对齐小数点
        if (decimalPart.size() > other.decimalPart.size()) {
            other.decimalPart += string(decimalPart.size() - other.decimalPart.size(), '0');
        } else {
            decimalPart += string(other.decimalPart.size() - decimalPart.size(), '0');
        }
        // 记录小数点位置
        int decimalPointPos = decimalPart.size(); // 10^-(decimalPointPos)
        // 忽略小数点，组合为长整数(不考虑符号)
        string num1 = integerPart + decimalPart;
        string num2 = other.integerPart + other.decimalPart;
        // 解析符号
            // 同号相加
            if (isNegative == other.isNegative) {
                // 1. isNegative == true
                // -A + -B => -(|A| + |B|)
                // 2. +A + +B => |A| + |B|
                res = isNegative ? '-' + longIntAdd(num1, num2) : longIntAdd(num1, num2);
            } else {
            // 异号相加
                res = isNegative ? longIntMinus(num2, num1) : longIntMinus(num1, num2);
                // 1. isNegative == true
                // -A + + B => |B| - |A|

                // 2. (+A + -B) => |A| - |B|
            }
            // 创建新的DecimalNumber对象
            DecimalNumber result("0");
            // 分离整数部分和小数部分
            result.integerPart = res.substr(0, res.size() - decimalPointPos);
            result.decimalPart = res.substr(res.size() - decimalPointPos);
            return result;
    }

    // 重载运算符 -
    DecimalNumber operator-(DecimalNumber& other) {
        string res = "";
        // 对齐小数点
        if (decimalPart.size() > other.decimalPart.size()) {
            other.decimalPart += string(decimalPart.size() - other.decimalPart.size(), '0');
        } else {
            decimalPart += string(other.decimalPart.size() - decimalPart.size(), '0');
        }
        
        // 记录小数点位置
        int decimalPointPos = decimalPart.size(); // 10^-(decimalPointPos)

        // 忽略小数点，组合为长整数(不考虑符号)
        string num1 = integerPart + decimalPart;
        string num2 = other.integerPart + other.decimalPart;

        // 同号相减
        if (isNegative == other.isNegative) {
            // +A - +B => |A| - |B|
            // -A - -B => B - A
            res = isNegative ? longIntMinus(num2, num1) : longIntMinus(num1, num2);
        } else { // 异号相减
            // +A - -B => A + B
            // -A - +B => -(A + B)
            res = isNegative ? '-' + longIntAdd(num1, num2) : longIntAdd(num1, num2);
        }

        DecimalNumber result("0");

        // 分离整数部分和小数部分
        result.integerPart = res.substr(0, res.size() - decimalPointPos);
        result.decimalPart = res.substr(res.size() - decimalPointPos);
        return result;
    }
    // 将整数部分和小数部分重新组合为字符串
    string toString() {
        string res = "";
        if (isNegative) res += '-';

        // 处理整数部分的前导零
        int nonZeroPos = 0;
        while (nonZeroPos < integerPart.length() && integerPart[nonZeroPos] == '0') {
            nonZeroPos++;
        }

        string intPartWithoutLeadingZeros = integerPart.substr(nonZeroPos);

        // 如果整个整数部分都是零
        if (intPartWithoutLeadingZeros.empty()) {
            intPartWithoutLeadingZeros = "0";
        } else {
            // 插入逗号
            for (int i = intPartWithoutLeadingZeros.size() - 3; i > 0; i -= 3) {
                intPartWithoutLeadingZeros.insert(i, ",");
            }
        }
        res += intPartWithoutLeadingZeros;

        // 处理小数部分的后导零
        while (!decimalPart.empty() && decimalPart.back() == '0') {
            decimalPart.pop_back();
        }

        // 添加小数部分（如果有）
        if (!decimalPart.empty()) res += '.' + decimalPart;

        return res;
    }
private:
    void removeComma() {
        int len = integerPart.size();
        for (int i = 0; i < len; i++) {
            if (integerPart[i] == ',') {
                integerPart.erase(i, 1);
                i--;
            }
        }
    }
    string longIntAdd(const string& num1, const string& num2) {
        // num1, num2 >= 0
        string res = "";
        int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
        int carry = 0;
        while (idx1 > -1 || idx2 > -1 || carry) {
            int digit1 = (idx1 >= 0) ? num1[idx1--] - '0' : 0;
            int digit2 = (idx2 >= 0) ? num2[idx2--] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            res += to_string(sum % 10);
        } 
        reverse(res.begin(), res.end());
        return res;
    }
    string longIntMinus(const string& num1, const string& num2) {
        // num1, num2 >= 0
        if (cmpAbsoluteVal(num2, num1)) return '-' + longIntMinus(num2, num1);

        string res = "";
        int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
        int carry = 0;
        while (idx1 > -1 || idx2 > -1 || carry) {
            int digit1 = (idx1 >= 0) ? num1[idx1--] - '0' : 0;
            int digit2 = (idx2 >= 0) ? num2[idx2--] - '0' : 0;

            int diff = digit1 - digit2 - carry;
            carry = diff < 0 ? 1 : 0;
            res += to_string((diff + 10) % 10);
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // 前一个数大于后一个数返回ture
    bool cmpAbsoluteVal(const string& num1, const string& num2) {
        if (num1.size() != num2.size()) {
            return false;
        }
        // 默认同长整数
        for (int i = 0; i < num1.length(); i++) {
            if (num1[i] == num2[i]) continue;
            if (num1[i] > num2[i]) return true;
            if (num1[i] < num2[i]) return false;
        }
        return false;
    }
};

int main() {
    int n;
    cin >> n;
    string num1, num2, op;
    while (n--) {
        cin >> op >> num1 >> num2;
        DecimalNumber num1Dec(num1);
        DecimalNumber num2Dec(num2);
        DecimalNumber result("0");

        if (op == "+") {
            result = num1Dec + num2Dec;
        } else if (op == "-") {
            result = num1Dec - num2Dec;
        }
        cout << result.toString() << endl;
    }
    return 0;
}