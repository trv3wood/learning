/*已知Sn=1 + 1/2 + 1/3 + ... + 1/n。
显然对于任意一个整数K，当n足够大的时候，Sn大于K。
现给出一个整数K（1 <= K <= 15），要求计算出一个最小的n，
使得Sn > K。
输入
多组输入。每组一行，每行输入一个整数K（1 <= K <= 15）。
输出
每组输出一个整数n。
样例输入 Copy
2
7
样例输出 Copy
4
616*/
#include <bits/stdc++.h>
using namespace std;

//void calculate(int k, double Sn = 0, long long n = 1) {
    //if(Sn <= k) {
        //Sn += (1.0 / n);
        //return calculate(k, Sn, n + 1);
    //} else
        //cout << n - 1 << endl;
//}

void calculate(int k) {
    double Sn = 0;
    long long n = 1;
    while(Sn <= k) {
        Sn += (1.0 / n);
        n++;
    }
    cout << n - 1 << endl;
}

int main() {
    int k;
    while(cin >> k)
        calculate(k);
}