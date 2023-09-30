#include <iostream>
using namespace std;
//用迭代公式计算平方根
double squareRoot(int n,double epsilon){
    double x0=n*0.5,x1;
    if(n<0){
        throw invalid_argument("n must be positive");
    } 
    else if(n==0 || n==1){
        return n;
    }
    else
    while(abs(x1*x1-n)>=epsilon) {
        x1=(n/x0+x0)*0.5;
        x0=x1;
    }
    return x1;
};

int main(){
    int n;
    double epsilon=1e-8;
    while (cin>>n)
    {
        cout<<squareRoot(n,epsilon)<<endl;
    }
    
}