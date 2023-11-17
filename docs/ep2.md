# midtermExam
## A
- find midNum
```cpp
//给你一个正整数 n，找出满足下述条件的中枢整数x：
//1和x之间的所有元素之和等于x和n之间所有元素之和。如果存在返回中枢整数x，不存在返回-1。1≤ n≤ 100000
//例如
//输入 8
//1+2+3+4+5+6=6+7+8=21
//输出 6
//given a positive integer n, find the central integer x satisfying:
//the sum of all elements between 1 and x is equal to the sum of all elements between x and n.
//if exists, return x, else return -1. 1≤ n≤ 100000
//for example:
//input 8
//1+2+3+4+5+6=6+7+8=21
//output 6
#include <iostream>
using namespace std;

//define a function to calculate the sum of a to b
inline int loopAdd(int a, int b) {
    int res = 0;
    res = (a + b) * (b - a + 1) / 2;
    return res;
}

//search the midNum
int find(int& n) {
    if(n == 1)
        return 1;
    int midNum = n - 1;
    int front = loopAdd(1, midNum);//sum of 1 to midNum
    int back = loopAdd(midNum, n);//sum of midNum to n
    while(midNum > n / 2 && midNum < n) {
        if(front == back)//find the midNum
            return midNum;
        else if(front > back) {
            
            //midNum is too big
            //move the midNum(like a pointer) to the left
            front -= midNum;
            midNum -= 1;
            back += midNum;
        }
        else {
            return -1;  
        }
    }
    return -1;
}
int main() {
    int n;
    while(cin >> n) {
        cout << find(n) << endl;
    }
}
```
## B
- 位分割
```cpp
//给你一个正整数x，请你将它按照位分割成两个非负整数 x1和 x2，
//满足：x1和x2的和最小，上述得到的整数没有前导0。
// 10 ≤ x  ≤  1 000 000 000，超出范围的输出 -1。
//given a positive integer x, split it into two non-negative integers x1 and x2,
//satisfying: the sum of x1 and x2 is the smallest, and the above integers have no leading 0.
// 10 ≤ x  ≤  1 000 000 000，output -1 if out of range.
#include <string>
#include <iostream>
#include <climits>
using namespace std;

int breakSum(int x) {
    if(x < 10 || x > 1000000000) {return -1;}
    string str = to_string(x);
    int len = str.length();
    int min = INT_MAX;
    for(int i = 1; i < len; i++) {
        int x1 = stoi(str.substr(0,i));
        int x2 = stoi(str.substr(i,len-i));
        if(x1 + x2 < min) {
            min = x1 + x2;
        }
    }
    return min;
}
int main() {
    int x;
    while(cin >> x) {
        cout << breakSum(x) << endl;
    }
}
```
## C
```cpp
//L代表火车的长度，D代表隧道的距离，t代表时间
//求过了一段时间t后，火车在隧道内的长度
//L represents the length of the train, D represents the distance of the tunnel, and t represents the time
//Find the length of the train in the tunnel after a period of time t
#include <iostream>
using namespace std; 

int main() {
    float L,D,t;
    const float v = 10.0;
    while(cin >> L >> D >> t) {
        float time2 = D / v;//time to pass the tunnel
        float time1 = L / v;//time to pass the train
        if(L <= D) {
            //if the length of the train is less than the distance of the tunnel
            if(t <= time1) {
                cout << v * t << endl;
            }
            else if(t > time2) {
                cout << (L - v * (t - time2)) << endl;
            }
            else if(t > time1 && t <= time2) {
                cout << L << endl;
            }
        }
        else {
            //if the length of the train is greater than the distance of the tunnel
            if( t < time2) {cout << v * t << endl;}
            else if(t >= time2 && t < time1) {cout << D << endl;}
            else {
                cout << D - v*(t - time1) << endl;
            }
        }
    }
}
```
