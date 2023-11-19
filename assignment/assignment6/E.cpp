/*集合中的元素通常是字符。设计程序，用无符号整数表示 ASCII码表中的字符集合，
用位运算实现各种基本集合运算（并集、交集、差集（第一个集合相对于第二个集合））。
输入
首先输入两个集合的长度，再输入两个集合的字符（在ASCII码表中的字符）
输出
两个集合运算的结果，包含3种运算。（首先是交集、然后是并集、最后是差集，每一行代表一个运算结果，
数据间隔一个空格，具体样式详见示例）
样例输入 Copy
5 2
1 2 3 4 5
2 6
3 6
5 + -
* / 8 5 - &
样例输出 Copy
1 2 3 4 5 6
2
1 3 4 5
& * + - / 5 8
- 5
+*/
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n1, n2;
    while(cin >> n1 >> n2) {
        set<char> s1, s2;
        char c;
        for(int i = 0; i < n1; i++) {
            cin >> c;
            s1.insert(c);
        }
        for(int i = 0; i < n2; i++) {
            cin >> c;
            s2.insert(c);
        }
        set<char> s3, s4, s5;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
        set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s4, s4.begin()));
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s5, s5.begin()));
        for(auto it = s3.begin(); it != s3.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        for(auto it = s4.begin(); it != s4.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
        for(auto it = s5.begin(); it != s5.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}