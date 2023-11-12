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