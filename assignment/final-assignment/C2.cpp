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

class Integer {
public:
    static const int BASE = 10;
    static const int WIDTH = 1;
    vector<short> s;

    Integer(long long num = 0) {
        *this = num;
        for (int n : s) cout << n << endl;
    }

    Integer operator=(long long num);
    Integer operator=(const string& str);

    bool operator<(const Integer& other) const;
    bool operator>(const Integer& other) const;
    bool operator<=(const Integer& other) const;
    bool operator>=(const Integer& other) const;

    bool operator!=(const Integer& other) const;
    bool operator==(const Integer& other) const;

    Integer operator+(const Integer& other) const;
    Integer operator+=(const Integer& other) {
        *this = *this + other;
        return *this;
    }

    Integer operator-=(const Integer& other);

};

Integer Integer::operator=(long long num) {
    do {
        s.emplace_back(num % BASE);
        num /= BASE;
    } while (num > 0);

    return *this; 
}

Integer Integer::operator=(const string& str) {
    s.clear();
    
}