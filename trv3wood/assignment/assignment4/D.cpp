#include <bits/stdc++.h>
using namespace std;
//回文数
bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int y = 0;//y是x的逆序数
    int tmp = x;
    while(tmp){
        y = y * 10 + tmp % 10;
        tmp /= 10;
    }
    return x == y;
}
//反转字符串hh(to do)
bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(!isalnum(s[i])) {
            i++;
            continue;
        }
        if(!isalnum(s[j])) {
            j--;
            continue;
        }
        if(tolower(s[i]) != tolower(s[j]))
            return false;
        i++;
        j--;
    }
    return true;
}
int main() {
    string s;
    while(cin >> s) {
        cout << isPalindrome(s) << endl;
    }
    return 0;
}