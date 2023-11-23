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
#include <bits/stdc++.h>
using namespace std;

//将字符x放入集合S中
unsigned putX(unsigned long &S, char x) {
    unsigned bitMask = 1;
    bitMask <<= x - 1;//隐式转换char为int
    S |= bitMask;
    return S;
}

//将集合S中的元素输出
void setDisplay(unsigned long S) {
    unsigned c;
    unsigned bitMask = 1;

    //判断集合是否为空
    if(!S) {
        cout << "{}" << endl;
        return;
    } else {
        cout << "{";
        //遍历集合中的元素
        //ASCII码表中的可见字符是从33开始的,所以从33开始遍历
        for(c = 33; c <= 126; c++) {
            if(!S)
                break;
            if(S & bitMask) {//判断集合中是否有该元素

                //将整数的ASCII码转换为字符
                cout << static_cast<char>(c);
                cout << ","; 
            }

            //右移一位
            S >>= 1;
        }

        //去掉最后一个逗号
        cout << "\b}" << endl;
    }
    return; 
}

//并集
unsigned long Union(unsigned long set1, unsigned long set2) {
    return set1 | set2;
}

//交集
unsigned long intersection(unsigned long set1, unsigned long set2) {
    return set1 & set2;
}

//差集
unsigned long difference(unsigned long set1, unsigned long set2) {
    return set1 & (~ (set1 & set2)); 
}

int main() {
    unsigned long set1 = 0, set2 = 0;
    unsigned n1, n2;
    char x;
    while (cin >> n1 >> n2) {
        for(int i = 0; i < n1; i++) {
            cin >> x;
            putX(set1, x);
        }
        for(int i = 0; i < n2; i++) {
            cin >> x;
            putX(set2, x);
        }
        setDisplay(intersection(set1, set2));
        setDisplay(Union(set1, set2));
        setDisplay(difference(set1, set2));
        set1 = 0;
        set2 = 0;
    }
    return 0;
}