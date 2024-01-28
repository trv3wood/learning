
#include <bits/stdc++.h>
using namespace std;

class DecimalNumber {
private:
    string integerPart;
    string decimalPart;
    bool sign;
    string add(const string& num1, const string& num2) const;
    string subtract(const string& num1, const string& num2) const; 
    bool cmpAbsoluteVal(const string& num1, const string& num2) const;
    DecimalNumber inverse();

public:
    DecimalNumber(const string& num);
    DecimalNumber() {
        integerPart = "ERROR";
        decimalPart = "";
        sign = true;
    }
    DecimalNumber operator+(DecimalNumber& other); 
    DecimalNumber operator-(DecimalNumber& other); 
    DecimalNumber operator*(const DecimalNumber& other);
    DecimalNumber operator/(DecimalNumber& other);
    string toString(); 
};

//int times = 0;
//char operation;
//string num1Str, num2Str;
//int main() {
    //cin >> times;
    //while (times--) {
        //cin >> operation >> num1Str >> num2Str;
        //DecimalNumber num1(num1Str);
        //DecimalNumber num2(num2Str);
        //if (operation == '*') {
            //cout << (num1 * num2).toString() << endl;
        //} else if (operation == '/') {
            //cout << (num1 / num2).toString() << endl;
        //}
    //}
//}

int main() {
    DecimalNumber num1("1000");
    DecimalNumber num2("10");
    cout << (num1 / num2).toString() << endl;

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
    // cout << "[debug] created " << (sign ? '+' : '-')  << integerPart << (!decimalPart.empty() ? '.' + decimalPart : "") << endl;
    for (int i = integerPart.size() - 1; i >= 0; i--) {
        if (integerPart[i] == ',') {
            integerPart.erase(i, 1);
        }
    }
}

DecimalNumber DecimalNumber::operator+(DecimalNumber& other) {
    string res = "";
    // 对齐小数点
    if (decimalPart.size() > other.decimalPart.size()) {
        other.decimalPart += string(decimalPart.size() - other.decimalPart.size(), '0');
    } else {
        decimalPart += string(other.decimalPart.size() - decimalPart.size(), '0');
    }
    
    int decimalPointPos = decimalPart.size(); // 10^-(decimalPointPos)

    // 忽略小数点，组合为长整数(不考虑符号)
    string num1 = integerPart + decimalPart;
    string num2 = other.integerPart + other.decimalPart;

    // 解析符号
    if (sign == other.sign) {
        res = sign ? add(num1, num2) : '-' + add(num1, num2);
    } else {
        res = sign ? subtract(num1, num2) : subtract(num2, num1);
    }
    DecimalNumber result("0");

    // 分离整数部分和小数部分
    result.integerPart = res.substr(0, res.size() - decimalPointPos);
    result.decimalPart = res.substr(res.size() - decimalPointPos);
    return result;
}

string DecimalNumber::add(const string& num1, const string& num2) const {
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

string DecimalNumber::subtract(const string& num1, const string& num2) const {
    // num1, num2 >= 0
    if (cmpAbsoluteVal(num2, num1)) return '-' + subtract(num2, num1);

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

bool DecimalNumber::cmpAbsoluteVal(const string& num1, const string& num2) const {
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

DecimalNumber DecimalNumber::operator-(DecimalNumber& other) {
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
    if (sign == other.sign) {
        res = sign ? subtract(num1, num2) : subtract(num2, num1);
    } else { // 异号相减
        res = sign ? add(num1, num2) : '-' + add(num1, num2);
    }

    DecimalNumber result("0");

    // 分离整数部分和小数部分
    result.integerPart = res.substr(0, res.size() - decimalPointPos);
    result.decimalPart = res.substr(res.size() - decimalPointPos);

    return result;
}

string DecimalNumber::toString() {
    if (integerPart == "ERROR") return  "ERROR";

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

DecimalNumber DecimalNumber::operator*(const DecimalNumber& other) {
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
        res = add(res, tmp);
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

DecimalNumber DecimalNumber::operator/(DecimalNumber& divisor) {
    string divisorStr = divisor.integerPart + divisor.decimalPart;
    string thisStr = integerPart + decimalPart;
    if (divisorStr.find_first_not_of('0') > 6) return DecimalNumber();
    if (thisStr  == "0") return DecimalNumber("0");
    DecimalNumber inverseDivisor = divisor.inverse();
    return inverseDivisor * (*this);
}

DecimalNumber DecimalNumber::inverse() {
    //if (decimalPart.empty()) {
        //long double num;
        //stringstream(integerPart) >> num;
        //return DecimalNumber(to_string(1 / num));
    //}
    DecimalNumber thisCopy = *this;
    DecimalNumber guess("0.5");

    int maxIterations = 20; 
    for (int i = 0; i < maxIterations; i++) {
        cout << "[debug] guess: " << guess.toString() << endl;
        DecimalNumber current = DecimalNumber("2") * guess;
        DecimalNumber current2 = thisCopy * guess * guess;
        guess = current - current2;
    }
    cout << "[debug] guess: " << guess.toString() << endl;
    return guess;
}