/*若将一个正整数化为二进制数，在此二进制数中，我们将数字1的个数多于数字0的个数的这类二进制数称为A类数，否则就称其为B类数。
例如：
(13)10=(1101)2,其中1的个数为3，0的个数为1，则称此数为A类数；
(10)10=(1010)2,其中1的个数为2，0的个数为2，称此数为B类数；
(24)10=(11000)2,其中1的个数为2，0的个数为3，则称此数为B类数。
程序要求：
输入n个整数x，(n<=100)，(1<=x<=1000)，分别求出其中A类数和B类数的个数。
输入
多组输入。每次输入一行，包含n个整数(n<=100)，以0结束，整数间以单个空格隔开。
输出
对应多组输出。每次输出一行，包含两个整数，分别是A类数的个数和B类数的个数，中间以单个空格隔开。
样例输入 Copy
13 10 24 0
23 111 999 8 0
0
样例输出 Copy
1 2
3 1
0 0
提示
多组测试用例，每组输入以输入0结束*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while(getline(cin, str)) {
        stringstream ss(str);
        int num;
        vector<int> nums;
        while(ss >> num)
            nums.emplace_back(num);
        nums.pop_back();

        
        int A = 0;
        int B = 0;
        for(int n : nums) {
            int count = 0;
            int x = n;
            int lg = 0;

            //计算n的二进制表示中1的个数
            while(x > 0) {
                //x >> 1表示x除以2
                x = (x >> 1);
                //lg表示n的二进制表示的长度
                lg++;
            }

            //计算n的二进制表示中0的个数
            //n & (n - 1)表示将n的二进制表示中最右边的1变为0
            while(n > 0) {
                n &= (n - 1);
                count++;
            }

            //如果1的个数多于0的个数，那么n就是A类数，否则就是B类数
            if(count > lg - count)
                A++;
            else
                B++;
        }
        cout << A << " " << B << endl;
    }
}