/*现有1，5，10三种面额的硬币，已知初始情况下的硬币数量，求每次交易后硬币的数量，为顾客找零钱时，希望选用的硬币数量最少，


比如手上硬币数量充裕时，3元的物品支付10元硬币，那么需要消耗手中的1个5元硬币和2个1元硬币，如果手上没有5元硬币，那么需要消耗7个1元硬币
输入
第一行三个数字，表示面额从小到大初始的各个硬币数量(仅输入一次初始硬币数量)
随后若干行每行4个整数，表示物品的价格，面额从小到大用户支付的各类硬币的数量，已经确保有足够的钱找零，且支付的金额大于价格
输出
三个数字，每次交易后手头的各种硬币数量，用空格隔开
样例输入 Copy
10 0 3
3 0 0 1
10 0 2 0
9 4 0 1
12 0 1 1
样例输出 Copy
3 0 4
3 2 4
7 1 5
4 2 6
提示
仅输入一次初始硬币数量，请while(cin后面每一行的4条数据)*/
#include <bits/stdc++.h>
using namespace std;

struct Coins {
    int one;
    int five;
    int ten;
    Coins(int o, int f, int t) {
        one = o;
        five = f;
        ten = t;
    }
    int givenBack(int price) {
        return (this->one + this->five * 5 + this->ten * 10) - price;
    }
};
int One;
int Five;
int Ten;
int price;

int main() {
    while(cin >> One >> Five >> Ten) {
        Coins origin(One, Five, Ten);
        while(cin >> price >> One >> Five >> Ten) {
            Coins paid(One, Five, Ten);

            origin.one += paid.one;
            origin.five += paid.five;
            origin.ten += paid.ten;

            int back = paid.givenBack(price);
            int idealTen = back / 10;
            int idealFive = (back % 10) / 5;
            int idealOne = ((back % 10) % 5);

            if(idealTen > origin.ten) {
                idealFive += (idealTen - origin.ten) * 2;
                idealTen = origin.ten;
            } 
            if(idealFive > origin.five) {
                idealOne += (idealFive - origin.five) * 5;
                idealFive = origin.five;
            }
             
            
            origin.one -= idealOne;
            
            origin.five -= idealFive;
            
            origin.ten -= idealTen;
            
            cout << origin.one << " " << origin.five << " " << origin.ten << endl;
        }
    }
}