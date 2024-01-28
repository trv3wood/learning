#include <bits/stdc++.h>
using namespace std;

class DecimalNumber {
public:
    string integerPart;
    string decimalPart;
    bool sign = true;

    DecimalNumber(const string& num); // 已经实现
    bool operator<(const DecimalNumber& other); // 已经实现
};

std::string add(const std::string& a, const std::string& b);
std::string subtract(const std::string& a, const std::string& b);
std::string multiply(const std::string& a, const std::string& b);

// 用于计算大数的倒数
std::string newtonRaphsonInverse(const std::string& d);

// 使用牛顿-拉弗森方法的除法
std::string divide(const std::string& a, const std::string& b); 


int main() {
    std::string a = "12345678901234567890";
    std::string b = "987654321";

    std::string result = divide(a, b);
    std::cout << "Result: " << result << std::endl;

    return 0;
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

bool DecimalNumber::operator<(const DecimalNumber& other) {
    if (sign != other.sign) {
        return !sign;
    } else {
        if (sign) {
            if (integerPart.size() != other.integerPart.size()) {
                return integerPart.size() < other.integerPart.size();
            } else {
                return integerPart < other.integerPart;
            }
        } else {
            if (integerPart.size() != other.integerPart.size()) {
                return integerPart.size() > other.integerPart.size();
            } else {
                return integerPart > other.integerPart;
            }
        }
    }
}

string add(const string& a, const string& b) {
    if (a[0] == '-' && b[0] == '-') {
        return '-' + addInt(a.substr(1), b.substr(1));
    } else if (a[0] == '-') {
        return subtract(b, a.substr(1));
    } else if (b[0] == '-') {
        return subtract(a, b.substr(1));
    } else {
        return addInt(a, b);
    }
}

std::string addInt(const std::string& a, const std::string& b) {
    std::string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 10;
        sum %= 10;
        result += sum + '0';
    }
    std::reverse(result.begin(), result.end());
    return result;
}

std::string newtonRaphsonInverse(const std::string& d) {
    // 初始估计值
    std::string x = "0.5"; 
    std::string two = "2";
    int maxIterations = 10;
    for (int i = 0; i < maxIterations; ++i) {
        // x_n(2 - dx_n)
        x = multiply(x, subtract(two, multiply(d, x)));
    }
    return x;
}

std::string divide(const std::string& a, const std::string& b) {
    std::string inverseB = newtonRaphsonInverse(b);
    return multiply(a, inverseB);
}