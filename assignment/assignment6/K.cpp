/*用带头结点的有序单向链表可以存放集合，如图所示。头结点不存放集合元素，仅为操作方便而设置。使用这种数据结构，设计集合的输入、输出和各种基本运算的函数。
输入
首先输入两个集合的长度，然后输入集合的元素
输出
输出集合的并集、交集、差集（第一个集合相对于第二个集合而言），每一行表示一个运算结果，集合之间用空格表示
样例输入 Copy
5 4
1 2 2 3 3
1 2 5 9
8 9
1 2 5 6 9 8 3 5
2 5 89 56 48 5 9 2 0
样例输出 Copy
1 2 3 5 9
1 2
3
0 1 2 3 5 6 8 9 48 56 89
2 5 9
1 3 6 8*/
#include <bits/stdc++.h>
using namespace std;

struct List {
    int data;
    List* next;
    List(int d, List* n) : data(d), next(n) {}
    List() {}
    ~List() {
        List* p = this;
        while(p) {
            List* tmp = p;
            p = p->next;
            delete tmp;
        }
    }
};

int main() {
    int len1, len2;
    
    while(cin >> len1 >> len2) {
        //create list
        List* head1 = new List();
        List* head2 = new List();
        List* p1 = head1;
        List* p2 = head2;
        for(int i = 0; i < len1; i++) {
            int tmp;
            cin >> tmp;
            p1->next = new List(tmp, nullptr);
            p1 = p1->next;
            
        }
        for(int i = 0; i < len2; i++) {
            int tmp;
            cin >> tmp;
            p2->next = new List(tmp, nullptr);
            p2 = p2->next;
        }
        p1 = head1->next;
        p2 = head2->next;

        //sort
        for(List* i = p1; i; i = i->next) {
            for(List* j = i->next; j; j = j->next) {
                if(i->data > j->data) {
                    int tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
            }
        }
        for(List* i = p2; i; i = i->next) {
            for(List* j = i->next; j; j = j->next) {
                if(i->data > j->data) {
                    int tmp = i->data;
                    i->data = j->data;
                    j->data = tmp;
                }
            }
        }
        //union
        set<int> s;
        for(;p1;p1 = p1->next) s.insert(p1->data);
        for(;p2;p2 = p2->next) s.insert(p2->data);
        for(auto i : s) cout << i << " ";
        cout << endl;

        //intersection
        p1 = head1->next;
        p2 = head2->next;
        set<int> s1;
        set<int> common;
        for(;p1;p1 = p1->next) s1.insert(p1->data);
        for(;p2;p2 = p2->next) {
            if(s1.count(p2->data))
                common.insert(p2->data);
        }
        for(auto i : common) cout << i << " ";
        cout << endl;

        //difference
        p1 = head1->next;
        p2 = head2->next;
        set<int> diff;
        for(;p1;p1 = p1->next) diff.insert(p1->data);
        for(;p2;p2 = p2->next) {
            if(diff.count(p2->data))
                diff.erase(p2->data);
        }
        for(auto i : diff) cout << i << " ";
        cout << endl;

        //delete
        delete head1;
        delete head2;

        
    }
}