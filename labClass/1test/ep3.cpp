#include <iostream>
#include <iomanip>
using namespace std;
//计算小球从高度h落下经过的路程和第n次反弹的高度
//输入
//输入一个整数h，表示小球的初始高度，h <= 1000
//输出
//输出两个数，第一个数表示小球从高度h落下经过的路程，
//第二个数表示小球第n次反弹的高度，两个数之间用一个空格隔开，保留4位小数
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