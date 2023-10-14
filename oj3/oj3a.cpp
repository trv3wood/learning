#include <iostream>
#include <cmath>
using namespace std;

double sh(double x){
    double output =(exp(x)-exp(-x))/2.0;
    return output;
}

int main(){
    int x;
    while(cin>>x){
        double dy = 1 + sh(x);
        double y = sh(dy) /(sh(2*x)+sh(3*x));
        cout<<y<<endl;
    }
}