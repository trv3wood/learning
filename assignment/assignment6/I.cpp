/*输入一行字符，按输入字符的反序建立一个字符结点的单向链表，并输出该链表中的字符。
输入
先输入一个整数，表示即将输入的字符串的个数，然后空格，输入一串字符（字符之间不要空格）
输出
反序字符串（不要空格间隔）
样例输入 Copy
5 abcde
10 abcdefghij
2 om
3 xyz
6 1wq02+
样例输出 Copy
edcba
jihgfedcba
mo
zyx
+20qw1*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char c;
    Node* last;
    Node(char ch, Node* l) : c(ch), last(l) {}
    Node() {}
};

int main() {
    int len;
    while(cin >> len) {
        //反转
        string str;
        for(int i = 0; i < len; i++) {
            char ch;
            cin >> ch;
            str += ch;
        }
        reverse(str.begin(), str.end());
        //建立链表
        Node* head = new Node(str[0], NULL);
        Node* p = head;
        for(int i = 1; i < len; i++) {
            Node* q = new Node(str[i], NULL);
            p->last = q;
            p = q;
        }
        //输出
        p = head;
        while(p != NULL) {
            cout << p->c;
            p = p->last;
        }
        cout << endl;
    }
}