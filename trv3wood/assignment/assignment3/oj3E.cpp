//勒让德多项式求值
//从键盘上输入 x和n的值，使用递归函数求pn(x)的值。
#include <iostream>

float Pn(float &x, float n) {
    if (n == 0) {
        return 1.0;
    }
    else if (n == 1) {
        return x;
    }
    else
        return ((2 * n - 1) * Pn(x, n - 1) - (n - 1) * Pn(x, n - 2)) / n;
}

int main() {
    float x, n;
    while (std::cin >> x >> n) {
        std::cout << Pn(x, n) << std::endl;
    }
}