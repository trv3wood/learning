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

//2023/11/23
//好难...正经人谁会用链表写这个啊...
//还是看看远处K.cpp的set吧

//2023/11/30
//好吧,我还是写了一下链表。K.cpp在OJ上内存超限了，我也不知道为什么，可能是因为我用了set吧。
//怀疑是OJ新加的限制，因为我之前写的K.cpp是可以通过的。
//K2.cpp在OJ上可以通过，但是我觉得这个代码写的很烂，而且我也不知道为什么要用链表写这个。

//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n) {
        data = d;
        next = n;
    }

    Node() {}

    void insert(int x) {
        //判重
        for (Node* ptr = this->next; ptr; ptr = ptr->next) {
            if (ptr->data == x)
                return;
        }

        if (this->next == nullptr) {
            // Insert directly if the list is empty
            this->next = new Node(x, nullptr);
        } else if (this->next->data >= x) {
            // Insert to the first position of the list
            Node* newNode = new Node(x, this->next);
            this->next = newNode;
        } else {
            Node* current = this->next;

            while (current->next != nullptr && current->next->data < x) {
                current = current->next;
            }

            // Now, current->next is either nullptr or the first node greater than or equal to x
            Node* newNode = new Node(x, current->next);
            current->next = newNode;
        }
    }
};
int len1;
int len2;

int main() {

    while(cin >> len1 >> len2) {
        Node* head1 = new Node(0, nullptr);
        Node* head2 = new Node(0, nullptr);
        
        int tmp;
        for(int i = 0; i < len1; i++) {
            cin >> tmp;
            head1->insert(tmp);
        }
        
        for(int i = 0; i < len2; i++) {
            cin >> tmp;
            head2->insert(tmp);
        }

        //Union
        Node* unionHead = new Node(0, nullptr);
        for(Node* ptr1 = head1->next; ptr1; ptr1 = ptr1->next) {
            unionHead->insert(ptr1->data);
        }
        for(Node* ptr2 = head2->next; ptr2; ptr2 = ptr2->next) {
            unionHead->insert(ptr2->data);
        }

        //Intersection
        Node* intersectionHead = new Node(0, nullptr);
        
        for(Node* ptr1 = head1->next; ptr1; ptr1 = ptr1->next) {
            for(Node* ptr2 = head2->next; ptr2; ptr2 = ptr2->next) {
                if(ptr1->data == ptr2->data) {
                    intersectionHead->insert(ptr1->data);
                    break;//跳出内层循环
                }
            }
        }

        //Difference
        Node* differenceHead = new Node(0, nullptr);
        for(Node* ptr1 = head1->next; ptr1; ptr1 = ptr1->next) {
            bool flag = true;
            for(Node* ptr2 = head2->next; ptr2; ptr2 = ptr2->next) {
                if(ptr1->data == ptr2->data) {
                    flag = false;
                    break;//跳出内层循环
                }
            }
            if(flag) {//如果ptr1不在head2中
                differenceHead->insert(ptr1->data);
            }
        }
        
        //Output
        for(Node* ptr = unionHead->next; ptr; ptr = ptr->next) {
            cout << ptr->data << " ";
        }
        cout << endl;

        for(Node* ptr = intersectionHead->next; ptr; ptr = ptr->next) {
            cout << ptr->data << " ";
        }
        cout << endl;

        for(Node* ptr = differenceHead->next; ptr; ptr = ptr->next) {
            cout << ptr->data << " ";
        }
        cout << endl;

        delete head1;
        delete head2;
        delete unionHead;
        delete intersectionHead;
        delete differenceHead;
    }
}
