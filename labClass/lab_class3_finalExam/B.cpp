/*两个单词如果包含相同的字母，次序不同，则称为字母易位词。判断两个单词是否是字母易位词，是输出Yes，不是输出No。
输入
两个不同的单词,都是小写字母
输出
是否是字母易位词，是输出Yes，不是输出No
样例输入 Copy
silent
listen
split
lisp
样例输出 Copy
Yes
No*/
#include <bits/stdc++.h>
using namespace std;

string str1;
string str2;

bool isSameChar(string& str1, string& str2) {
    for(char c : str1) {
        if(str2.find(c) == string::npos)
            return false;
    }
    return true;
}

bool isSamePos(string& str1, string& str2) {
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}
int main() {
    while(cin >> str1 >> str2) {
        if(str1.size() != str2.size())
            cout << "No" << endl;
        else {
            if(isSameChar(str1, str2)) {
                if(isSamePos(str1, str2))
                    cout << "No" << endl;
                else
                    cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}