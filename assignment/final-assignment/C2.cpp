#include <bits/stdc++.h>
using namespace std;

class Unsigned {
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
    vector<int> nums;
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
    Unsigned operator*(const Unsigned& other) const;
    Unsigned operator/(const Unsigned& other) const;

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

Unsigned Unsigned::operator*(const Unsigned& other) const {
    Unsigned res;
    res.nums.resize(nums.size() + other.nums.size());
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < other.nums.size(); j++) {
            res.nums[i + j] += nums[i] * other.nums[j];
            res.nums[i + j + 1] += res.nums[i + j] / BASE;
            res.nums[i + j] %= BASE;
        }
    }
    res.removeLeadingZeros();
    return res;
}

Unsigned Unsigned::operator/(const Unsigned& other) const {
    Unsigned res;
    res.nums.resize(nums.size());
    int cur;
    Unsigned tmp;
    for (int i = nums.size() - 1; i >= 0; i--) {
        tmp = tmp * Unsigned(BASE) + Unsigned(nums[i]);
        cur = 0;
        while (tmp >= other) {
            tmp -= other;
            cur++;
        }
        res.nums[i] = cur;
    }
    res.removeLeadingZeros();
    return res;
}

class Float : public Unsigned {
private:
    bool sign = true;
    Unsigned integerPart;
    Unsigned decimalPart;
public:
    Float(double num = 0) {
        *this = num;
    }
    Float operator=(double num);
    Float operator=(const string& number);
    Float(const std::string& numberStr) {
        *this = numberStr;
    }

    bool operator<(const Float& other) const;
    bool operator>(const Float& other) const;
    bool operator==(const Float& other) const;

    Float operator+(const Float& other) const;
    Float operator-(const Float& other) const;
    Float operator*(const Float& other) const;
    Float operator/(const Float& other) const;

    friend ostream& operator<<(ostream& out, Float x) {
        if (!x.sign) out << '-';
        out << x.integerPart << '.' << x.decimalPart;
        return out;
    }

};

int main() {
    Float a, b;
    a = 1.2;
    b = 2.3;
    b = 1.0;
    return 0;
}

bool Float::operator<(const Float& other) const {
    if (sign != other.sign) return !sign;
    if (integerPart != other.integerPart) return integerPart < other.integerPart;
    return decimalPart < other.decimalPart;
}

bool Float::operator>(const Float& other) const {
    if (sign != other.sign) return sign;
    if (integerPart != other.integerPart) return integerPart > other.integerPart;
    return decimalPart > other.decimalPart;
}

bool Float::operator==(const Float& other) const {
    return (sign == other.sign) && (integerPart == other.integerPart) && (decimalPart == other.decimalPart);
}

Float Float::operator=(double num) {
    sign = num >= 0;
    num = abs(num);
    integerPart = (long long)num;
    if ((double)num == (long long)num) {
        decimalPart = 0;
        return *this;
    }
    decimalPart = (long long)(((double)num - (long long)num) * 10000000000) + 1; 
    return *this;
}

Float Float::operator=(const string& number) {
    string numCopy = number;
    removeComma(numCopy);
    if (numCopy[0] == '-') {
        sign = false;
        numCopy.erase(0, 1);
    } else {
        sign = true;
    }
    int dotPos = numCopy.find('.');
    if (dotPos == string::npos) {
        integerPart = numCopy;
        decimalPart = 0;
    } else {
        integerPart = numCopy.substr(0, dotPos);
        decimalPart = numCopy.substr(dotPos + 1);
    }
    return *this;
}

Float Float::operator+(const Float& other) const {
    Float res;
    
    return res;
}