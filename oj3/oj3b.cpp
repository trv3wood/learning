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