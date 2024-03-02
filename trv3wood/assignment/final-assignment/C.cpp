/*小数结果末尾最多保留10位小数，四舍五入，除数绝对值小于10(-6)则报ERROR

Sample Input Copy
3
*
12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
/
1,234.567890123456789012
0.0000000000123
/
66,666,666,666,666,666,666,666,666,666,666.6666666666
-2
Sample Output Copy
152,415,787,532,388,367,504,953,515,625,666,819,450,083,828,733,757,049,236,500,533,455,762,536,198,787,501,905,199,875,019,052,100
ERROR
-33,333,333,333,333,333,333,333,333,333,333.3333333333*/
#include <bits/stdc++.h>
using namespace std;

string addInt(const string& num1, const string& num2);
bool cmpIntAbsoluteVal(const string& num1, const string& num2);
string subtract(const string& num1, const string& num2);

class DecimalNumber {
private:
    string integerPart;
    string decimalPart;
    bool sign;

public:
    DecimalNumber(const string& num);
    DecimalNumber operator+(const DecimalNumber& other) const;
    DecimalNumber operator-(DecimalNumber other) const;
    DecimalNumber operator*(const DecimalNumber& other) const;
    DecimalNumber operator/(const DecimalNumber& other) const;
    string combine() const;
    string stringOutput();
};

int main() {
    //DecimalNumber divided("1000");
    //DecimalNumber divisor("10");
    //DecimalNumber two("2");
    //DecimalNumber x_n("0.5");
    //DecimalNumber t1 = x_n * two;
    //DecimalNumber t2 = divisor * x_n * x_n;
    //cout << "[debug] x_n * two: " << (x_n * two).stringOutput() << endl;
    //cout << "[debug] divisor * x_n * x_n: " << (divisor * x_n * x_n).stringOutput() << endl;
    //cout << "[debug] iterated: " << (t1 - t2).stringOutput() << endl;
    DecimalNumber res = (DecimalNumber("1") - DecimalNumber("2.5"));
    cout << "[debug] 1 - 2.5: " << res.combine() << endl;
}

string addInt(const string& num1, const string& num2) {
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

DecimalNumber::DecimalNumber(const string& num) {
    if (num[0] == '-') {
        sign = false;
        if (num.find('.') != string::npos) {
            integerPart = num.substr(1, num.find('.') - 1);
            decimalPart = num.substr(num.find('.') + 1);
        } else {
            integerPart = num.substr(1);
            decimalPart = "";
        }
    } else {
        sign = true;
        if (num.find('.') != string::npos) {
            integerPart = num.substr(0, num.find('.'));
            decimalPart = num.substr(num.find('.') + 1);
        } else {
            integerPart = num;
            decimalPart = "";
        }
    }
    cout << "[debug] created " << (sign ? '+' : '-')  << integerPart << (!decimalPart.empty() ? '.' + decimalPart : "") << endl;
    for (int i = integerPart.size() - 1; i >= 0; i--) {
        if (integerPart[i] == ',') {
            integerPart.erase(i, 1);
        }
    }
}

string DecimalNumber::combine() const {
    string r;
    if (!sign) r = '-' + r;
    r += integerPart;
    if (!decimalPart.empty()) r += '.' + decimalPart;
    return r;
}

string DecimalNumber::stringOutput() {
    string res = "";
    if (!sign) res += '-';

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

DecimalNumber DecimalNumber::operator+(const DecimalNumber& other) const {
    string res = "";
    string otherDec = other.decimalPart;
    string dec = decimalPart;
    // 对齐小数点
    if (decimalPart.size() > other.decimalPart.size()) {
        otherDec += string(decimalPart.size() - other.decimalPart.size(), '0');
    } else {
        dec += string(other.decimalPart.size() - decimalPart.size(), '0');
    }
    
    int decimalPointPos = dec.size(); // 10^-(decimalPointPos)

    // 忽略小数点，组合为长整数(不考虑符号)
    string num1 = integerPart + dec;
    string num2 = other.integerPart + otherDec;

    // 解析符号
    if (sign == other.sign) {
        res = sign ? addInt(num1, num2) : '-' + addInt(num1, num2);
    } else {
        res = sign ? subtract(num1, num2) : subtract(num2, num1);
    }
    if (decimalPointPos) res.insert(res.size() - decimalPointPos, '.', 1);
    DecimalNumber result(res);

    return result;
}

DecimalNumber DecimalNumber::operator-(DecimalNumber other) const {
    string res = "";
    // 对齐小数点
    string otherDec = other.decimalPart;
    string dec = decimalPart;
    if (decimalPart.size() > other.decimalPart.size()) {
        otherDec += string(decimalPart.size() - other.decimalPart.size(), '0');
    } else {
        dec += string(other.decimalPart.size() - decimalPart.size(), '0');
    }
    
    // 记录小数点位置
    int decimalPointPos = dec.size(); // 10^-(decimalPointPos)

    bool resSign = true;

    // 忽略小数点，组合为长整数(不考虑符号)
    string num1 = integerPart + dec;
    string num2 = other.integerPart + otherDec;

    // 同号相减
    if (sign == other.sign) {
        res = sign ? subtract(num1, num2) : subtract(num2, num1);
        if (sign) {
            res = subtract(num1, num2);
            if (cmpIntAbsoluteVal(num1, num2)) resSign = false;
        } else {
            res = subtract(num2, num1);
            if (cmpIntAbsoluteVal(num2, num1)) resSign = false;
        }
    } else { // 异号相减
        res = addInt(num1, num2);
        if (!sign) resSign = false;
    }

    DecimalNumber result("0");
    result.integerPart = res.substr(0, res.size() - decimalPointPos);
    result.decimalPart = res.substr(res.size() - decimalPointPos);
    result.sign = resSign;

    return result;
}

bool cmpIntAbsoluteVal(const string& num1, const string& num2) {// <
    if (num1.size() == num2.size()) {
        for (int i = 0; i < num1.size(); i++) {
            if (num1[i] == num2[i]) continue;
            if (num1[i] > num2[i]) return false;
            if (num1[i] < num2[i]) return true;
        }
    }
    return num1.size() < num2.size();
}

string subtract(const string& num1, const string& num2) {

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

DecimalNumber DecimalNumber::operator*(const DecimalNumber& other) const {
    string res = "0";
    string thisVal = integerPart + decimalPart;
    string otherVal = other.integerPart + other.decimalPart;

    int decimalPointPos = decimalPart.size() + other.decimalPart.size();
    int thisLen = thisVal.size();

    while (thisLen--) {
        int thisDigit = thisVal[thisLen] - '0';
        int carry = 0;
        string tmp = "";
        int otherLen = otherVal.size();
        while (otherLen--) {
            int otherDigit = otherVal[otherLen] - '0';
            int sum = carry + thisDigit * otherDigit;
            carry = sum / 10;
            tmp = to_string(sum % 10) + tmp;
        }
        if (carry) tmp = to_string(carry) + tmp;
        for (int i = 0; i < thisVal.size() - thisLen - 1; i++) tmp += '0';
        res = addInt(res, tmp);
    }

    DecimalNumber result("0");
    result.sign = (sign == other.sign) ? true : false;
    if (decimalPointPos == 0) {
        result.integerPart = res;
    } else {
        result.integerPart = res.substr(0, res.size() - decimalPointPos);
        result.decimalPart = res.substr(res.size() - decimalPointPos);
    }
    return result;
}

DecimalNumber DecimalNumber::operator/(const DecimalNumber& other) const {
    DecimalNumber divisor = other;
    DecimalNumber inverseDiv("0.01"); // 初始估计值
    DecimalNumber two("2");

    int maxIterations = 10;
    for (int i = 0; i < maxIterations; ++i) {
        // x_n(2 - dx_n)
        DecimalNumber tmp = (two - divisor * inverseDiv);

        inverseDiv = inverseDiv * tmp;
    }

    return (*this) * inverseDiv;
}