#include <iostream>
#include <cmath>
#include <iomanip>
//输入三个正整数m,n,p，计算并输出下式的值，保留8位小数。
//注意判断运算中的溢出情况。
inline long double sum(int& n,int x){
    long long add = 1;
    for(int i = 2;i < n + 1;++i){
        add += std::pow((i),x);
    }
    static_cast<long double>(add);
    return add;
}
int main(){
    int m,n,p;
    while (std::cin>>m>>n>>p){
        long double result = (sum(m,1)+sum(n,3))/sum(p,5);
        std::cout <<std::fixed<<std::setprecision(8)<< result << std::endl;
    }
}