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