#include <bits/stdc++.h>
using namespace std;
//找出x1到x2之间的所有整数中，约数个数最多的整数，如果有多个，输出最大的那个，以及约数的个数
//find the integer with the most divisors between x1 and x2, if there are multiple, output the largest one and the number of divisors
void solve(int& x1,int& x2) {
    int maximum = 0;
    int count = 0;
        
    for(int i = x1;i <= x2;i++) {
        int temp = 0;//count the number of divisors
        for(int j = 1;j <= i;j++) {
            //if i is divisible by j, then j is a divisor of i
            if(i % j == 0) temp++;
        }
        if(temp > count) {
            //if the number of divisors of i is greater than the current maximum, update the maximum
            count = max(count,temp);
            maximum = max(maximum,i);
            temp = 0;//reset temp
        }
        else if(temp == count) {
            //if the number of divisors of i is equal to the current maximum, update the maximum
            maximum = max(maximum,i);
            temp = 0;
        }
        else temp = 0;//reset temp
    }
    cout << maximum << " " << count << endl;
}

int main() {
    int x1,x2;
    while(cin >> x1 >> x2) {
        solve(x1,x2);
    }
}