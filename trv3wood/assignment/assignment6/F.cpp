/*使用结构类型表示复数。设计程序，输入两个复数，可以选择进行复数的+、—、* 或/ 运算，并输出结果。
输入
两个结构体表示的复数以及一个运算符
输出
这两个数的运算结果
样例输入 Copy
1 2 3 1 *
5 2 3 6 -
2.5 6 0.3 5 +
110.6 5.6 2 3 /
样例输出 Copy
1+7i
+2-4i
+2.8+11i
+18.3077-24.6615i
提示
注意题目中的结构体表示的一个复数采用两个double型变量进行定义；
输出的时候注意使用函数setiosflags(rnm要用个锤子，纯纯误导人)*/

//这题不难，只是输出格式有点麻烦

#include <iostream>
#include <iomanip>
using namespace std;

struct ComplexNumber {
    //定义结构体表示复数
    double real, imag;
    //构造函数
    ComplexNumber(double r, double i) {
        real = r;
        imag = i;
    }
};

int main() {
    double real1, imag1, real2, imag2;
    char operation;
    while (std::cin >> real1 >> imag1 >> real2 >> imag2 >> operation) {
        ComplexNumber c1(real1, imag1), c2(real2, imag2);
        ComplexNumber result(0, 0);
        
        switch (operation) {
            case '+':
                result.real = c1.real + c2.real;
                result.imag = c1.imag + c2.imag;
                break;
            case '-':
                result.real = c1.real - c2.real;
                result.imag = c1.imag - c2.imag;
                break;
            case '*':
                result.real = c1.real * c2.real - c1.imag * c2.imag;
                result.imag = c1.real * c2.imag + c1.imag * c2.real;
                break;
            case '/':
                result.real = (c1.real * c2.real + c1.imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
                result.imag = (c1.imag * c2.real - c1.real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
                break;
            default:
                continue;
        }
        cout << result.real << showpos << result.imag << "i" << endl;
    }
    return 0;
}