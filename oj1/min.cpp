#include <iostream>
int main(){
    int a,b,c;
    while (std::cin>>a>>b>>c)//取最小的整数
    {
        std::cout<<(a<=b?(a<=c?a:c):(b<=c?b:c))<<std::endl;
    }
}