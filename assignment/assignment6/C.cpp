/*设计重载函数，使用按位异或 (^) 运算，实现快速交换两个整型变量和浮点型变量的值
Input
两个整数以及两个浮点数（均空格间隔）
Output
交换后的结果（各个数之间以空格间隔）
Sample Input Copy
2 3 5.3 6.2
5 6 33.9 99.5
Sample Output Copy
3 2 6.2 5.3
6 5 99.5 33.9*/
#include <bits/stdc++.h>
using namespace std;

void exchange(int& num1, int& num2) {
    num1 = num1 ^ num2;
    num2 = num1 ^ num2;
    num1 = num1 ^ num2;
}

void exchange(float& num1, float& num2) {
    int *pnum1, *pnum2;
    pnum1 = (int*)(&num1);
    pnum2 = (int*)(&num2);
    *pnum1 = *pnum1 ^ *pnum2;
    *pnum2 = *pnum1 ^ *pnum2;
    *pnum1 = *pnum1 ^ *pnum2;
}

int main() {
    int in1, in2;
    float fn1, fn2;
    while (cin >> in1 >> in2 >> fn1 >> fn2) {
        exchange(in1, in2);
        exchange(fn1, fn2);
        std::cout << in1 << " " << in2 << " " << fn1 << " " << fn2 << std::endl;
    }
}
