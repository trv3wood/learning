/*整数左移一位相当于将该数乘以 2。编写一个函数:
unsigned power2( unsigned number, unsigned pow );
使用移位运算计算 numberX2pow，并以整数形式输出计算结果。注意考虑数据的溢出。
Input
一个整数（空格间隔）一个代表左移几位的整数
Output
移位之后的运算结果
Sample Input Copy
2 5
2 1
65 2
Sample Output Copy
64
4
260
HINT
注意使用无符号整数*/
#include <bits/stdc++.h>
using namespace std;

unsigned long power2(unsigned number, unsigned pow) {
    for (int i = 0; i < pow; i++) {
        number = number << 1;
    }
    return number;
}

int main() {
    int number, pow;
    while (cin >> number >> pow) {
        cout << power2(number, pow) << endl;
    }
    return 0;
}
