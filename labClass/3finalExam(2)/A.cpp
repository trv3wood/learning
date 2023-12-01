/*给定一个仅包含字符 '('，')'，'{'，'}'，'[' 和 ']' 的字符串 s，判断输入字符串是否有效。
如果输入字符串有效，则：
开放括号必须由相同类型的括号关闭。
必须按正确顺序关闭开放括号。
每个关闭括号都有相应的相同类型的开放括号。
 
例1：
输入：s =“（{}）”
输出：true
 
例2：
输入：s =“（）[] {}”
输出：true
 
例3：
输入：s =“（]”
输出：false*/
#include <bits/stdc++.h>
using namespace std;

bool isVaild(string s) {
    unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> stk;
    for(char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stk.empty() || stk.top() != pairs[c]) {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main() {
    string str;
    while(cin >> str) {
        if(isVaild(str)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}