/*设有说明语句:
struct List { int data; List * next; };
List *head;
head是有序单向链表的头指针。请编写函数:
void Count( List * head );
计算并输出链表中有相同值的结点及其个数。例如，若数据序列为:
2 3 3 3 4 5 5 6 6 6 6 7 8 9 9
则输出结果为:
data number
3     3
5     2    
6     4
9     2
可以用例 5-18 的程序生成有序链表，测试 Count 函数。
输入
一个链表的长度（也就是链表中有多少个数据），需要存进链表的数据（注意输入的数据要是升序）
输出
相同值的节点及其个数（中间以一个空格间隔）
样例输入 Copy
5
1 1 1 2 2
8
1 1 2 2 2 3 3 3
样例输出 Copy
1 3
2 2
1 2
2 3
3 3*/
#include <bits/stdc++.h>
using namespace std;

struct List {
    int data;
    List* next;
    List(int d, List* n) : data(d), next(n) {}
    List() {}
};

void Count(List * head) {
    map<int, int> m;
    List* p = head->next;
    while(p) {
        m[p->data]++;
        p = p->next;
    }
    for(auto it = m.begin(); it != m.end(); it++) {
        if(it->second > 1)
            cout << it->first << " " << it->second << endl;
    }

}

int main() {
    int len;
    while(cin >> len) {
        List* head = new List();
        List* p = head;
        //建立链表
        for(int i = 0; i < len; i++) {
            int d;
            cin >> d;
            List* q = new List(d, NULL);
            p->next = q;
            p = q;
        }
        //计算相同值的节点及其个数
        Count(head);
        delete head;
    }
}