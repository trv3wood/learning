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

//emmm我没用位运算，直接用了set
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n1, n2;
    while(cin >> n1 >> n2) {
        set<unsigned> s1, s2;
        for(int i = 0; i < n1; i++) {
            char tmp;
            cin >> tmp;
            unsigned t = toascii(tmp);
            s1.insert(t);
        }
        for(int i = 0; i < n2; i++) {
            char tmp;
            cin >> tmp;
            unsigned t = toascii(tmp);
            s2.insert(t);
        }
       
        set<unsigned> s4;
        set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s4, s4.begin()));
        for(auto i : s4) cout << char(i) << " ";cout << endl;
        set<unsigned> s3;
        set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
        for(auto i : s3) cout << char(i) << " ";cout << endl;
        set<unsigned> s5;
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s5, s5.begin()));
        for(auto i : s5) cout << char(i) << " ";
        cout << endl;
    }
    return 0;
}