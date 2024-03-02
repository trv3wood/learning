//给你一个正整数x，请你将它按照位分割成两个非负整数 x1和 x2，
//满足：x1和x2的和最小，上述得到的整数没有前导0。
// 10 ≤ x  ≤  1 000 000 000，超出范围的输出 -1。
//given a positive integer x, split it into two non-negative integers x1 and x2,
//satisfying: the sum of x1 and x2 is the smallest, and the above integers have no leading 0.
// 10 ≤ x  ≤  1 000 000 000，output -1 if out of range.
#include <string>
#include <iostream>
#include <climits>
using namespace std;

int breakSum(int x) {
    if(x < 10 || x > 1000000000) {return -1;}
    string str = to_string(x);
    int len = str.length();
    int min = INT_MAX;
    for(int i = 1; i < len; i++) {
        int x1 = stoi(str.substr(0,i));
        int x2 = stoi(str.substr(i,len-i));
        if(x1 + x2 < min) {
            min = x1 + x2;
        }
    }
    return min;
}
int main() {
    int x;
    while(cin >> x) {
        cout << breakSum(x) << endl;
    }
}
