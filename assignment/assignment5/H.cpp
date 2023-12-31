/*一个正整数，如果它能被7整除，或者它的十进制表示法中某一位上的数字为7，
则称其为与7相关的数，否则称其为与7无关的数。
现给一个正整数n（n <=100），如果n是与7无关的数，则输出n的平方，否则，输出n。
输入
多组输入。每组一行，每行输入一个整数n（n <= 100）。
输出
每组一个整数作为输出。
样例输入 Copy
28
22
17
33
78
样例输出 Copy
28
484
17
1089
78*/
#include <bits/stdc++.h>
using namespace std;

bool is7related(int n) {
    if(n % 7 == 0)
        return true;
    else {
        while(n) {
            if(n % 10 == 7)
                return true;
            else
                n /= 10;
        }
    }
    return false;
}
int main() {
    int n;
    while(cin >> n) {
        if(is7related(n))
            cout << n << endl;
        else
            cout << n * n << endl;
    }
    return 0;
}