/*大数除法（高精度实数除法）的测试样例需要涵盖各种可能的情况，以确保算法的正确性和稳健性。下面提供一些测试样例，包括不同长度的数字、特殊值（如0）、以及可能导致精度问题的情况。

### 测试样例 1: 简单的除法
- 输入：`a = "1000"`, `b = "10"`
- 输出：`"100"`

### 测试样例 2: 长数字除法
- 输入：`a = "12345678901234567890"`, `b = "987654321"`
- 输出：一个精确的结果，这个测试可以用来检测算法是否能处理非常长的数字。

### 测试样例 3: 除数为1
- 输入：`a = "12345678901234567890"`, `b = "1"`
- 输出：`"12345678901234567890"`

### 测试样例 4: 被除数为0
- 输入：`a = "0"`, `b = "12345"`
- 输出：`"0"`

### 测试样例 5: 结果为小数
- 输入：`a = "1"`, `b = "3"`
- 输出：一个精确到合理小数位数的结果，例如 `"0.3333333333"`，具体的精度可以根据实际算法和需求设定。

### 测试样例 6: 结果为很大的数字
- 输入：`a = "12345678901234567890"`, `b = "0.00000000001"`
- 输出：一个非常大的数字，测试算法是否能处理极端大小的结果。

### 测试样例 7: 负数除法
- 输入：`a = "-12345678901234567890"`, `b = "987654321"`
- 输出：一个精确的负数结果。

### 测试样例 8: 边缘情况，除数非常小
- 输入：`a = "12345678901234567890"`, `b = "0.00000000000000000001"`
- 输出：一个非常大的数字，测试算法是否能处理除数非常小的情况。

确保在实现算法时考虑到了各种可能的边缘情况，并且对于每个测试样例都要仔细检查结果是否符合预期。如果算法在任何一个测试样例上失败，可能需要回顾算法的实现，查找并修复可能存在的问题。*/
#include <bits/stdc++.h>
using namespace std;

class Unsigned {
private:
    vector<int> nums;
protected:
    static const int WIDTH = 3;
    static const int BASE = 1000;
    void removeLeadingZeros() {
        while (nums.size() > 1 && nums.back() == 0) {
            nums.pop_back();
        }
    }

    void removeComma(string& s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',') {
                s.erase(i, 1);
                i--;
            } 
        }
    }
    int strToInt(const string& str) {
        stringstream ss {str};
        int num;
        ss >> num;
        return num;
    }

public:
    Unsigned(long long num = 0) {
        *this = num;
    }
    Unsigned operator=(long long num);
    Unsigned operator=(const string& number);

    Unsigned(const std::string& numberStr) {
        *this = numberStr;
    }

    bool operator<(const Unsigned& other) const;
    bool operator>(const Unsigned& other) const;
    bool operator<=(const Unsigned& other) const;
    bool operator>=(const Unsigned& other) const;

    bool operator==(const Unsigned& other) const;
    bool operator!=(const Unsigned& other) const {
        return !(*this == other);
    }

    Unsigned operator+(const Unsigned& other) const;
    Unsigned operator+=(const Unsigned& other) {
        *this = *this + other;
        return *this;
    }

    Unsigned operator-(const Unsigned& other) const;
    Unsigned operator-=(const Unsigned& other) {
        *this = *this - other;
        return *this;
    }
    // Unsigned mod(const Unsigned& other) const;

    friend istream& operator >> (istream& in, Unsigned& x) {
        string s;
        if (!(in >> s)) return in;
        in >> s;
        x = s;
        return in;
    }

    friend ostream& operator << (ostream& out, Unsigned x) {
        x.removeLeadingZeros();
        if (x.nums.size() < 2) {
            out << x.nums.back();
            return out;
        }
        out << x.nums.back() << ',';
        char buf[20];
        for (int i = x.nums.size() - 2; i > 0; i--) {
            sprintf(buf, "%03d", x.nums[i]); // 3 digits
            for (int j = 0; j < strlen(buf); j++) {
                out << buf[j];
            }
            out << ',';
        }
        sprintf(buf, "%03d", x.nums[0]); 
        out << buf;
        return out;
    }

};

class Integer: public Unsigned {
public:
    bool sign = true;
    Unsigned absoluteVal;

    Integer(long long num = 0) {
        *this = num;
    }

    Integer operator=(long long num); 

    Integer(const string& s) {
        *this = s;
    }

    Integer operator=(const string& s);

    bool operator<(const Integer& other) const;
    bool operator>(const Integer& other) const;
    bool operator<=(const Integer& other) const;
    bool operator>=(const Integer& other) const;

    bool operator==(const Integer& other) const;
    bool operator!=(const Integer& other) const {
        return !(*this == other);
    }

    Integer operator+(const Integer& other) const;
    Integer operator+=(const Integer& other) {
        *this = *this + other;
        return *this;
    }

    Integer operator-(const Integer& other) const;
    Integer operator-=(const Integer& other) {
        *this = *this - other;
        return *this;
    }

    friend ostream& operator<<(ostream& out, Integer x) {
        if (!x.sign) out << '-';
        out << x.absoluteVal;
        return out;
    }

    friend istream& operator>>(istream& in, Integer& x) {
        string s;
        if (!(in >> s)) return in;
        x = s;
        return in;
    }
};

//int main() {
    //Unsigned u1;
    //u1 = "1000000000000000000000000000000000000000";
    //Unsigned u2;
    //u2 = "999999999999999999999999999999999999999";
    //std::cout << u2 - u1 << std::endl;
//}
/*
2
+
1,111,111,111,111,111,111,111,111,111,111,111,111 
222,222,222,222,222,222,222,222,222,222,222,222
-
98,765,432,198,765,432,198,765,432,198,765,432,198,765,432,198,765
12,345,678,901,234,567,890,123,456,789,012,345,678,901,234,567,890
样例输出 Copy
1,333,333,333,333,333,333,333,333,333,333,333,333
86,419,753,297,530,864,308,641,975,409,753,086,519,864,197,630,875
*/

string s1 = ""; 
string s2 = "";
char operation;
int n;
int main() {
    cin >> n;
    while (n--) {
        cin >> operation >> s1 >> s2;
        Integer i1 = s1;
        Integer i2 = s2;
        if (operation == '+') {
            std::cout << (i1 + i2) << std::endl;
        } else if (operation == '-') {
            std::cout << (i1 - i2) << std::endl;
        }
    }
}

Unsigned Unsigned::operator=(long long num) {
    nums.clear();
    do {
        nums.push_back(num % BASE);
        num /= BASE;
    } while (num > 0);

    return *this; 
}

Unsigned Unsigned::operator=(const string& number) {
    nums.clear();
    string numCopy = number;
    removeComma(numCopy);
    // cout << "[debug] num: " << numCopy<< endl;
    int len = (numCopy.size() - 1) / WIDTH + 1;
    // cout << "[debug] len: " << len << endl;

    for (int i = 0; i < len; i++) {
        int end = numCopy.size() - i * WIDTH;
        int start = max(0, end - WIDTH);
        nums.emplace_back(strToInt(numCopy.substr(start, end - start)));
    }
    // cout << "[debug] *this: " << *this << endl;
    return *this;
}

Unsigned Unsigned::operator+(const Unsigned& other) const {
    Unsigned res;
    res.nums.clear();
    int carry = 0;
    int idx1 = 0, idx2 = 0;
    while (idx1 < nums.size() || idx2 < other.nums.size() || carry) {
        int sum = carry;
        if (idx1 < nums.size()) {
            sum += nums[idx1++];
            //cout << "[debug] nums[idx1 - 1]: " << nums[idx1 - 1] << endl;
            //cout << "[debug] idx1: " << idx1 << endl;
        }
        if (idx2 < other.nums.size()) {
            sum += other.nums[idx2++];
            //cout << "[debug] nums[idx2 - 1]: " << other.nums[idx2 - 1] << endl;
            //cout << "[debug] idx2: " << idx2 << endl;
        }
        carry = sum / BASE;
        res.nums.emplace_back(sum % BASE);
    }
    return res;
}

Unsigned Unsigned::operator-(const Unsigned& other) const { 
    //if (*this < other) {
        //Unsigned res = other - *this;
        //res.removeLeadingZeros();
        //res.nums.back() = -res.nums.back();
        //return res;
        //// throw std::runtime_error("Unsigned::operator-: negative result");
    //}
    Unsigned res;
    res.nums.clear();
    int carry = 0;
    int idx1 = 0, idx2 = 0;
    while (idx1 < nums.size() || idx2 < other.nums.size()) {
        int sum = -carry;
        sum += (idx1 < nums.size()) ? nums[idx1++] : 0;
        sum -= (idx2 < other.nums.size()) ? other.nums[idx2++] : 0;
        res.nums.emplace_back((sum + BASE) % BASE);
        carry = (sum < 0 ? 1 : 0);
    }
    return res;
}

bool Unsigned::operator<(const Unsigned& other) const {
    if (nums.size() != other.nums.size()) return nums.size() < other.nums.size();
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] == other.nums[i]) continue;
        if (nums[i] < other.nums[i]) return true;
        if (nums[i] > other.nums[i]) return false;
    }
    return false;
}

bool Unsigned::operator>(const Unsigned& other) const {
    if (nums.size() != other.nums.size()) return nums.size() > other.nums.size();
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] == other.nums[i]) continue;
        if (nums[i] > other.nums[i]) return true;
        if (nums[i] < other.nums[i]) return false;
    }
    return false;
}

bool Unsigned::operator==(const Unsigned& other) const {
    if (nums.size() != other.nums.size()) return false;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != other.nums[i]) return false;
    }
    return true;
}

bool Unsigned::operator<=(const Unsigned& other) const {
    return (*this == other) || (*this < other);
}

bool Unsigned::operator>=(const Unsigned& other) const {
    return (*this == other) || (*this > other);
}

Integer Integer::operator=(long long num) {
    if (num < 0) sign = false;
    absoluteVal = std::abs(num);
    return *this;
}

Integer Integer::operator=(const string& strNum) {
    if (strNum[0] == '-') {
        sign = false;
        absoluteVal = strNum.substr(1);
    } else {
        absoluteVal = strNum;
    }
    return *this;
}

bool Integer::operator<(const Integer& other) const {
    if (sign == other.sign) {
        if (sign) return absoluteVal < other.absoluteVal;
        else return absoluteVal > other.absoluteVal;
    } else {
        if (sign) return false;
        else return true;
    }
}

bool Integer::operator>(const Integer& other) const {
    if (sign == other.sign) {
        if (sign) return absoluteVal > other.absoluteVal;
        else return absoluteVal < other.absoluteVal;
    } else {
        if (sign) return true;
        else return false;
    }
}

bool Integer::operator<=(const Integer& other) const {
    if (sign == other.sign) {
        if (sign) return absoluteVal <= other.absoluteVal;
        else return absoluteVal >= other.absoluteVal;
    } else {
        if (sign) return false;
        else return true;
    }
}

bool Integer::operator>=(const Integer& other) const {
    if (sign == other.sign) {
        if (sign) return absoluteVal >= other.absoluteVal;
        else return absoluteVal <= other.absoluteVal;
    } else {
        if (sign) return true;
        else return false;
    }
}

bool Integer::operator==(const Integer& other) const {
    return (sign == other.sign) && (absoluteVal == other.absoluteVal);
}

Integer Integer::operator+(const Integer& other) const {
    Integer res;
    if (sign == other.sign) {
        res.sign = sign;
        res.absoluteVal = absoluteVal + other.absoluteVal;
    } else {
        if (absoluteVal > other.absoluteVal) {
            res.sign = sign;
            res.absoluteVal = absoluteVal - other.absoluteVal;
        } else {
            res.sign = other.sign;
            res.absoluteVal = other.absoluteVal - absoluteVal;
        }
    }
    return res;
}

Integer Integer::operator-(const Integer& other) const {
    Integer res;
    if (sign == other.sign) {
        if (absoluteVal > other.absoluteVal) {
            res.sign = sign;
            res.absoluteVal = absoluteVal - other.absoluteVal;
        } else {
            res.sign = !sign;
            res.absoluteVal = other.absoluteVal - absoluteVal;
        }
    } else {
        res.sign = sign;
        res.absoluteVal = absoluteVal + other.absoluteVal;
    }
    return res;
}