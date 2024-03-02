//梯形法求积分
//用函数指针作为参数
#include <iostream>
#include <cmath>

float function1(float& x) { 
    return 4.0 / (1.0 + x * x); 
}

float function2(float& x) {
    return std::sqrt(1.0 + x * x);
}

float function3(float& x) {
    return sin(x);
}

float integral(float (*funcPtr)(float&),float a,float b) {
    float h = (b - a) / 10000.0;
    float sum = 0;
    for (int i = 1; i < 10000; ++i) {
        float expression = a + i * h;
        sum += (*funcPtr)(expression);
    }
    return h * (((*funcPtr)(a) + (*funcPtr)(b)) / 2.0 + sum);
}

int main() {
    float (*funcPtr)(float&);
    funcPtr = function1;
    std::cout << integral(funcPtr, 0, 1) <<" ";
    funcPtr = function2;
    std::cout << integral(funcPtr, 1, 2) << " ";
    funcPtr = function3;
    std::cout << integral(funcPtr, 0, 3.14159 / 2.0) << " " <<
    std::endl;
}