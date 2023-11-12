/*将一组 C++关键字存放到一个 string 数组中，并找出这些关键字中的最小者。
输入
一个整数（代表即将输入的关键字个数），以及关键字
输出
最小的关键字
样例输入 Copy
5
while
int
double
if
for
3
int
char
if
样例输出 Copy
double
char*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(cin >> n) {
        string strs[n];
        for(int i = 0; i < n; i++)
            cin >> strs[i];
        string minKeyWord = strs[0];
        for(string word : strs) {
            if(word < minKeyWord)
                minKeyWord = word;
        }
        cout << minKeyWord << endl;
    }
}