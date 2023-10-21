# oj3题目
![oj3题目](/image/oj3_assignment.jpg)

## 目录
- oj3
   - [A 双曲函数计算](#A)
   - [B 溢出判断](#B)
   - [C 猜数(二分法)](#C)
   - [D 编写函数求最值](#D)
   - [E 多项式递归求和](#E)
   - [F 循环的等价递归](#F)
   - [G 梯形法求积分](#G)
   - [H 排序函数重载](#H)

## A
```cpp
#include <iostream>
#include <cmath>
using namespace std;
//实现关于双曲函数的计算
double sh(double x){
    double output =(exp(x)-exp(-x))/2.0;
    return output;
}

int main(){
    double x;
    while(cin>>x){
        double dy = 1 + sh(x);
        double y = sh(dy) /(sh(2*x)+sh(3*x));
        cout<<y<<endl;
    }
}
```
[返回目录](#目录)
## B
```cpp
#include <iostream> 
#include <cmath> 
#include <cfloat>
//输入三个正整数m,n,p，计算并输出下式的值 
//注意判断运算中的溢出情况。 
float sum(int& n,int x){ 
    int add = 1; 
    for(int i = 2;i < n + 1;++i){ 
        add += std::pow(i,x); 
    }  
    return add; 
} 
void calculate(int&m,int&n,int&p){
    float result = (sum(m,1)+sum(n,3))/sum(p,5);
    if(result<FLT_MAX&&(m+n)<=10000)
        std::cout<<result<<std::endl;
    else std::cout<<"溢出"<<std::endl;
 }
int main(){ 
    int m,n,p; 
    while (std::cin>>m>>n>>p){
        calculate(m,n,p);
    }
    return 0;
}
```
[返回目录](#目录)
## C
```cpp
#include <iostream>
//猜数
void guess(int& feedback, int& left, int& right) {
    if(feedback == 1) {
        right = (left+right)/2;
        std::cout<<(left+right)/2<<std::endl;
    }else if(feedback == -1) {
        left = (left+right)/2;
        std::cout<<(left+right)/2<<std::endl;
    }
}

int main() {
    std::cout<<500<<std::endl;
    int feedback,n=0;
    int left = 0; int right = 1000;
    while(std::cin>>feedback) {
        guess(feedback, left, right);
        n++;
        if(feedback == 0){
            std::cout<<"猜了"<<n<<"次"<<std::endl;
            return 0;
        }
    }
    return 0;
}
```
[返回目录](#目录)
## D
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
//求三个数最大值和最小值
//要求：把求最值的操作分别编写成两个函数，
//并使用指针或引用作为形式参数，把结果返回main函数
float Maximum(std::vector<float>& nums){
    std::vector<float>::iterator result =
    std::max_element(nums.begin(),nums.end());
    float max = *result;
    return max;
}
float Minimum(std::vector<float>& nums){
    std::vector<float>::iterator result =
    std::min_element(nums.begin(),nums.end());
    float min = *result;
    return min;
}

int main(){
    float a,b,c;
    while(std::cin>>a>>b>>c){
        std::vector<float> nums = {a,b,c};
        std::cout << "max = " << Maximum(nums) 
        << " min = " <<Minimum(nums)<<std::endl;
    }
    return 0;
}
```
[返回目录](#目录)
## E
```cpp
//勒让德多项式求值
//从键盘上输入 x和n的值，使用递归函数求pn(x)的值。
#include <iostream>

float Pn(float& x,float n) {
    if(n == 0) {
        return 1.0;
    }else if(n == 1){
        return x;
    }
    else
        return ((2*n-1) * Pn(x,n-1)-(n-1)*Pn(x,n-2))/n;
}

int main(){
    float x,n;
    while(std::cin>> x >> n){
        std::cout << Pn(x,n) << std::endl;
    }
}
```
[返回目录](#目录)
## F
```cpp
#include <iostream>

// 把循环函数修改为等价的递归函数

void print(int w, int row = 1, int column = 1) {
    if (row > w) {
        return;
    }
    std::cout << row << " ";
    if (column == row) {
        std::cout << std::endl;
        print(w, row + 1, 1);
    } else {
        print(w, row, column + 1);
    }
}

int main() {
    int w;
    print(5);
    return 0;
}
```
[返回目录](#目录)
## G
```cpp
//梯形法求积分
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

float integral(float (*funcPtr)(float&),float a,float b){
    float h = (b - a)/10000.0;
    float sum = 0;
    for(int i = 1;i < 10000;++i) {
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
    std::cout << integral(funcPtr, 0, 3.14159/2.0) << " " <<
    std::endl;
}
```
[返回目录](#目录)
## H
*重载函数*
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
//两个数从大到小输出
void _sort(float a,float b) {
    if(a>b){std::cout << a << " " << b <<std::endl;}
    else {std::cout << b << " " << a << std::endl;}
}

//三个数从大到小输出,使用vector,重载_sort函数
void _sort(float c,float d,float e) {
    std::vector<float> nums = {c, d, e};
    std::sort(nums.begin(),nums.end(),[](float a,float b){return a>b;});
    for(float i:nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    float a, b, c, d, e;
    while(std::cin >> a >> b >> c >> d >> e) {
        _sort(a,b);
        _sort(c,d,e);
    }
    return 0;
}
```
[返回目录](#目录)
