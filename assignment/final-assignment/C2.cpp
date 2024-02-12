#include <bits/stdc++.h>
class Float {
public:
    Float(const std::string &number = "0");
    Float(const Float &) = default;
    Float(Float &&) = default;
    Float &operator=(const Float &) = default;
    Float &operator=(Float &&) = default;
    Float operator=(const std::string &number);

    Float operator*(const Float &other) const;
    Float operator/(const Float &other) const;
    bool absoluteValLessThan(const Float& other) const; 
    bool operator<(const Float& other) const; 
    bool operator==(const Float& other) const; 

    std::string toString() const;
    void format();

private:
    bool isNegative = false;   // true for negative numbers
    std::vector<int> mantissa; // 尾数
    int exponent;              // 指数
    void roundMantissa() {
        if (exponent == mantissa.size()) return;
        if (mantissa.size() - exponent <= 10) {
            mantissa.insert(mantissa.end(), 10 - (mantissa.size() - exponent), 0);
            return;
        }

        if (mantissa[exponent + 10] >= 5) {
            for (int i = exponent + 9; i >= 0; i--) {
                mantissa[i]++;
                if (mantissa[i] < 10) break;
                if (i == 0) {
                    // 如果最高位也进位，则在最前面添加一个新的数字位
                    mantissa.insert(mantissa.begin(), 1);
                    exponent += 1; // 因为尾数变长了，指数也相应增加
                } else {
                    mantissa[i] = 0; // 当前位变为0，继续向更高位进位
                }
            }
        }
        mantissa.resize(exponent + 10);
    }
};

std::vector<int> multiplyByDigit(const std::vector<int>& mantissa, int digit);
bool isLessThan(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2);
std::vector<int> subtractMantissas(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2);

int n;
std::string num1;
std::string num2;
char operation;
Float n1, n2;

int main() {
    while (std::cin >> n) {
        while (n--) {
            std::cin >> operation >> num1 >> num2;
            n1 = num1;
            n2 = num2;
            Float res;
            if (operation == '*') {
                res = n1 * n2;
            } else if (operation == '/') {
                res = n1 / n2;
            }
            std::cout << res.toString();
        }
    }
}

// 辅助函数，用于尾数的乘法
std::vector<int> multiplyByDigit(const std::vector<int>& mantissa, int digit) {
    // 实现尾数和一个数字的乘法
    if (digit == 0) return std::vector(1, 0);
    std::vector<int> res(mantissa);
    int carry = 0;
    for (int i = res.size() - 1; i >= 0; i--) {
        res[i] = res[i] * digit + carry;
        carry = res[i] / 10;
        res[i] = res[i] % 10;
    }
    if (carry) res.insert(res.begin(), carry);
    return res;
}

// 辅助函数，用于判断第一个尾数是否小于第二个尾数
bool isLessThan(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2) {
    int start1 = 0, start2 = 0;
    for (int i = 0; i < mantissa1.size(); i++) {
        if (mantissa1[i] > 0) {
            start1 = i; break;
        }
    }
    for (int i = 0; i < mantissa2.size(); i++) {
        if (mantissa2[i] > 0) {
            start2 = i; break;
        }
    }
    if (mantissa1.size() - start1 < mantissa2.size() - start2) return true;
    if (mantissa1.size() - start1 > mantissa2.size() - start2) return false;
    for (int i = start1; i < mantissa1.size(); i++) {
        if (mantissa1[i] < mantissa2[i]) return true;
        if (mantissa1[i] > mantissa2[i]) return false;
    }
    return false;
}

// 辅助函数，用于尾数的减法
std::vector<int> subtractMantissas(const std::vector<int>& mantissa1, const std::vector<int>& mantissa2) {
    // 对齐两个尾数,不足的补0
    std::vector<int> res(mantissa1);
    std::vector<int> mantissa2Copy(mantissa2);
    if (mantissa2Copy.size() < res.size()) mantissa2Copy.insert(mantissa2Copy.begin(), res.size() - mantissa2Copy.size(), 0);
    if (mantissa2Copy.size() > res.size()) res.insert(res.begin(), mantissa2Copy.size() - res.size(), 0);

    // 从低位开始减
    for (int i = res.size() - 1; i >= 0; i--) {
        res[i] -= mantissa2Copy[i];
        if (res[i] < 0) {
            res[i] += 10;
            res[i - 1]--;
        }
    }

    // 去掉前导0
    while (res.size() > 1 && res[0] == 0) res.erase(res.begin());
    return res;
}

void Float::format() {
    if (exponent > mantissa.size()) {
        exponent = mantissa.size();
    }
    while (exponent > 1 && mantissa[0] == 0) {
        mantissa.erase(mantissa.begin());
        exponent--;
    }

    if (mantissa.size() == 1 && mantissa[0] == 0) {
        isNegative = false;
    }

    if (exponent < mantissa.size()) {
        for (int i = mantissa.size() - 1; i >= exponent; i--) {
            if (mantissa[i] == 0) {
                mantissa.erase(mantissa.begin() + i);
            } else {
                return;
            }
        }
    }
}

std::string Float::toString() const {
    std::string out;
    if (!exponent) return "ERROR\n";
    if (isNegative) out += '-';
    if (exponent < mantissa.size()) {
        for (int i = 0; i < exponent; i++) {
            out += mantissa[i] + '0';
            if ((exponent - i - 1) % 3 == 0 && (exponent - i - 1)) {
                out += ',';
            }
        }
        out += '.';
        for (int i = exponent; i < mantissa.size(); i++) {
            out += mantissa[i] + '0';
        }
    } else {
        for (int i = 0; i < mantissa.size(); i++) {
            out += mantissa[i] + '0';
            if ((mantissa.size() - i - 1) % 3 == 0 && (mantissa.size() - i - 1)) {
                out += ',';
            }
        }
    }
    out += '\n';
    return out;
}

bool Float::absoluteValLessThan(const Float& other) const { 
    if (exponent != other.exponent) return exponent < other.exponent;
    for (int i = 0; i < std::min(mantissa.size(), other.mantissa.size()); i++) {
        if (mantissa[i] == other.mantissa[i]) continue;
        if (mantissa[i] < other.mantissa[i]) return true;
        else return false;
    }
    if (mantissa.size() >= other.mantissa.size()) return false;
    else return true;
}

bool Float::operator<(const Float& other) const {
    if (isNegative == other.isNegative) {
        if (!isNegative) return absoluteValLessThan(other);
        else return other.absoluteValLessThan(*this);
    } else {
        return isNegative;
    }
}

bool Float::operator==(const Float& other) const {
    return exponent == other.exponent && mantissa == other.mantissa && isNegative == other.isNegative;
}

Float Float::operator/(const Float& divisor) const {    // 处理除以0的情况
    if (divisor.absoluteValLessThan(Float("0.000001"))) {
        Float error;
        error.exponent = 0;
        return error;
    }
    // 初始化结果
    Float result;
    // 除数为1
    if (divisor==Float("1")) {
        result = *this;
        result.roundMantissa();
        return result;
    }
    if (divisor==Float("-1")) {
        result = *this;
        result.isNegative = !isNegative;
        result.roundMantissa();
        return result;
    }

    // 去掉除数前导0
    std::vector<int> div(divisor.mantissa);
    while (div[0] == 0) {
        div.erase(div.begin());
    }
    std::vector<int> dividend(mantissa);
    while (dividend[0] == 0) {
        dividend.erase(dividend.begin());
    }
    dividend.insert(dividend.end(), 11, 0);

    
    // 余数
    std::vector<int> remainder;
    
    // 执行长除法
    for (int i = 0; i < dividend.size(); i++) {
        remainder.push_back(dividend[i]);
        
        while (remainder[0] == 0 && remainder.size() > 1) {
            remainder.erase(remainder.begin());
        }
        if (isLessThan(remainder, div) || remainder[0] == 0) { // 如果余数小于除数
            result.mantissa.push_back(0);
            if (i < dividend.size() - 11) result.exponent++;
            continue;
        }

        int quotientDigit = 1;
        while (true) {
            std::vector<int> tempDiv = multiplyByDigit(div, quotientDigit);
            if (isLessThan(remainder, tempDiv)) {
                quotientDigit--;
                break;
            } else if (remainder == tempDiv) {
                break;
            }
            quotientDigit++;
        }
        result.mantissa.push_back(quotientDigit); // 保存商的一位

        // 处理结果的尾数和指数
        if (i < dividend.size() - 11) result.exponent++;
        remainder = subtractMantissas(remainder, multiplyByDigit(div, quotientDigit));
    }
    // 结果的符号
    result.isNegative = (isNegative != divisor.isNegative);
    // 处理指数
    int dividendExp = mantissa.size() - exponent;
    int divisorExp = divisor.mantissa.size() - divisor.exponent;
    result.exponent = result.exponent - dividendExp + divisorExp; 

    result.format();
    // 四舍五入
    result.roundMantissa(); 
    
    return result;


}

Float Float::operator*(const Float& other) const {    
    Float res;
    res.mantissa.clear();
    res.mantissa.resize(mantissa.size() + other.mantissa.size() - 1, 0);

    // 计算指数
    int exponent1 = exponent ? mantissa.size() - exponent : 0;
    // LOG(exponent1)
    int exponent2 = other.exponent ? other.mantissa.size() - other.exponent : 0;
    // LOG(exponent2)
    res.exponent = res.mantissa.size() - exponent1 - exponent2;
    
    // 计算尾数
    for (int i = 0; i < mantissa.size(); i++) {
        for (int j = 0; j < other.mantissa.size(); j++) {
            res.mantissa[i + j] += mantissa[i] * other.mantissa[j];
        }
    }
    int carry = 0;
    for (int i = res.mantissa.size() - 1; i >= 0; i--) {
        res.mantissa[i] += carry;
        carry = res.mantissa[i] / 10;
        res.mantissa[i] %= 10;
    }
    if (carry) {// 如果最高位有进位
        res.mantissa.insert(res.mantissa.begin(), carry);
        res.exponent++;// 如果有进位，指数+1
    }
    res.isNegative = isNegative != other.isNegative;
    res.format();
    return res;

}

Float::Float(const std::string& number) {
    *this = number;
}

Float Float::operator=(const std::string& number) {
    if (number.empty()) {
        throw std::invalid_argument("Input string is empty");
    }
    mantissa.clear();
        
    size_t numberStart = 0;
    // 处理符号位
    if (number[0] == '-') {
        isNegative = true; // 负数
        numberStart = 1;
    } else {
        isNegative = false; // 正数
    }
    // 查找小数点的位置
    size_t pointPos = number.find('.', numberStart);

    if (pointPos == std::string::npos) { // 指数
        exponent = number.size() - numberStart;
    } else {
        exponent = pointPos - numberStart;
    }

    if (number.find(',', numberStart) != std::string::npos) {
        exponent -= (exponent / 4); // 逗号的影响
    }

    for (int i = numberStart; i < number.size(); i++) { // 尾数
        if (number[i] == ',' || number[i] == '.') continue;
        else mantissa.push_back(number[i] - '0');
    }
    return *this;
}