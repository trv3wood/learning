/*用带头结点的有序单向链表可以存放集合，如图所示。头结点不存放集合元素，仅为操作方便而设置。使用这种数据结构，
设计集合的输入、输出和各种基本运算的函数。
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
//好难...正经人谁会用链表写这个啊...
//还是看看远处K.cppd的set吧

#include <bits/stdc++.h>
using namespace std;

struct List {
    int data;
    List* next;
    List(int d, List* n) {
        data = d;
        next = n;
    }
    List() {}
    ~List() {
        delete next;
    }
};

List* getUnion(List* head1, List* head2) {
    List* unionList = new List();
    List* p = unionList;
    for (List* p1 = head1; p1 != nullptr; p1 = p1->next) {//将head1中的元素全部添加到unionList中
        if(p1->data == p->data) continue;// Add continue statement to avoid duplicate elements in the union
        p->next = new List(p1->data, nullptr);
        p = p->next;
    }
    for (List* p2 = head2; p2 != nullptr; p2 = p2->next) {
        bool flag = true;
        for (List* p1 = head1; p1 != nullptr; p1 = p1->next) {
            if (p2->data == p1->data) {
                flag = false;
                break;
            }
        }
        if(flag) {
            p->next = new List(p2->data, nullptr);
            p = p->next;
        }
    }
    return unionList->next;
}

List* getIntersection(List* head1, List* head2) {
    List* intersection = new List();
    List* p = intersection;
    for (List* p1 = head1; p1 != nullptr; p1 = p1->next) {
        for (List* p2 = head2; p2 != nullptr; p2 = p2->next) {
            if (p1->data == p2->data) {
                if(p1->data == p->data) break;// Add break statement to avoid duplicate elements in the intersection
                p->next = new List(p1->data, nullptr);
                p = p->next;
                break; // Add break statement to avoid duplicate elements in the intersection
            }
        }
    }
    return intersection->next;
}

List* getDifference(List* head1, List* head2) {
    List* difference = new List();
    List* p = difference;
    for(List* p1 = head1; p1 != nullptr; p1 = p1->next) {
        bool flag = true;
        for(List* p2 = head2; p2 != nullptr; p2 = p2->next) {
            if(p1->data == p2->data) {
                flag = false;
                break;
            }
        }
        if(flag) {
            if(p1->data == p->data) continue;// Add continue statement to avoid duplicate elements in the difference
            p->next = new List(p1->data, nullptr);
            p = p->next;
        }
    }
    return difference->next;
}

void displayList(List* head) {
    for(List* p = head; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }
    cout << endl;
}//displayList

List* sortAndRmDup(List* head) {
    List* p = head;
    while(p != nullptr) {
        List* q = p->next;
        while(q != nullptr) {
            if(p->data > q->data) {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    return head;
}//sortAndRmDup
int main() {
    int n1, n2;
    cin >> n1 >> n2;
    List* head1 = new List();
    List* head2 = new List();
    List* p1 = head1;
    List* p2 = head2;
    for(int i = 0; i < n1; i++) {
        int x;
        cin >> x;
        p1->next = new List(x, nullptr);
        p1 = p1->next;
    }
    for(int i = 0; i < n2; i++) {
        int x;
        cin >> x;
        p2->next = new List(x, nullptr);
        p2 = p2->next;
    }
    head1 = head1->next;
    head2 = head2->next;
    
    List* unionList = new List();
    List* intersection = new List();
    List* difference = new List();

    unionList = getUnion(head1, head2);
    intersection = getIntersection(head1, head2);
    difference = getDifference(head1, head2);

    unionList = sortAndRmDup(unionList);
    intersection = sortAndRmDup(intersection);
    difference = sortAndRmDup(difference);

    displayList(unionList);
    displayList(intersection);
    displayList(difference);

    delete unionList;
    delete intersection;
    delete difference;
    delete head1;
    delete head2;
    return 0;
}