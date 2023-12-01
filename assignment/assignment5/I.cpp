/*关于自然常数e有许多有趣的结果，
例如e等于表达式(1+1/n)^n在n趋于无穷时的极限，
又例如e等于表达式1+1/1!+1/2!+…+1/n!在n趋于无穷时的极限（n!为n的阶乘，即n*(n-1)*(n-2)…*3*2*1），
请根据输入的正整数n，计算上述两种表达式的比值，即((1+1/n)^n)/( 1+1/1!+1/2!+…+1/n!)，比值精确到4位小数。
输入
多组输入，每行一个正整数n
输出
按行输出上述比值，精确到4位小数
样例输入 Copy
1
4
5
8
9
19
99
999
999999
样例输出 Copy
1.0000
0.9014
0.9159
0.9439
0.9496
0.9749
0.9950
0.9995
1.0000*/
#include <bits/stdc++.h>
using namespace std;

//calculate e1 = (1 + 1 / n) ^ n
//计算e1 = (1 + 1 / n) ^ n
long double e1(int n) {
    long double res = 1.0;
    for(int i = 0; i < n; i++)
        res *= 1.0 + 1.0 / n;
    return res;
}

//calculate e2 = 1 + 1 / 1! + 1 / 2! + ... + 1 / n!
//计算e2 = 1 + 1 / 1! + 1 / 2! + ... + 1 / n!
long double e2(int n) {
    long double res = 1.0;
    long double nnn = 1.0;
    //note:limit in one loop
    //or it will be time out
    //注意：限制在一层循环
    //否则会超时
    for(int i = 1; i <= n; i++) {

        nnn *= (1.0 / i);
        res += nnn;
    }
    return res;
}

int main() {
    int n;
    while(cin >> n) {
        // cout << e1(n) << " " << e2(n) << endl;
        cout << fixed << setprecision(4) << (e1(n) / e2(n)) << endl;
    }
}