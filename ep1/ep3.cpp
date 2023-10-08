#include <iostream>
#include <iomanip>
using namespace std;
//correct
int main(){
    int h;
    while(cin>>h){
        double height = h * 1000;
        double S = height;
        int n = 0;
        while(height >= 1){
            height *= 0.5;
            S += 2 * height;
            n += 1;
        }
        cout<< n <<" "<<setprecision(4)<<fixed<< S *0.001<<endl;
    }
}