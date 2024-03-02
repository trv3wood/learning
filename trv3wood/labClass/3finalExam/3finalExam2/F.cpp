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

/// @brief class of coins including three attributes: one, five, ten and three methods: shouldGivenBack(private), Pay(private), back(public)
class Coins {
public:
    /// @brief three attributes of coins that store the number of coins
    int one;
    int five;
    int ten;
    Coins(int o, int f, int t) {
        one = o;
        five = f;
        ten = t;
    }
private:
    /// @brief calculate the money should be paid
    /// @param price the price of the goods
    /// @return money should be paid
    /// @note private method called by public method
    /// @note the object that calls this method should be the original coins
    int shouldGivenBack(int price) {
        return (this->one + this->five * 5 + this->ten * 10) - price;
    }
    /// @brief pay the money and update the number of coins
    /// @param paid the coins paid by the customer
    /// @note private method called by public method
    /// @note the object that calls this method should be the original coins
    void Pay(Coins paid) {
        this->one += paid.one;
        this->five += paid.five;
        this->ten += paid.ten;
    }
public:
    /// @brief change the money and update the number of coins
    /// @param price the price of the goods
    /// @param paid the coins paid by the customer
    /// @note public method called by main function
    /// @note the object that calls this method should be the original coins
    void back(int price, Coins paid) {
        int back = paid.shouldGivenBack(price);
        this->Pay(paid);
        //idealTen: the number of 10-yuan coins that should be given back
        //以此类推
        int idealTen = back / 10;
        int idealFive = (back % 10) / 5;
        int idealOne = ((back % 10) % 5);

        //如果没有足够的硬币找零，那么就用更小面额的硬币找零
        if(idealTen > this->ten) {
            idealFive += (idealTen - this->ten) * 2;
            idealTen = this->ten;
        }
        if(idealFive > this->five) {
            idealOne += (idealFive - this->five) * 5;
            idealFive = this->five;
        }
        
        //更新硬币数量
        this->one -= idealOne;
        this->five -= idealFive;
        this->ten -= idealTen;
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
            origin.back(price, paid);
            cout << origin.one << " " << origin.five << " " << origin.ten << endl;
        }
    }
}