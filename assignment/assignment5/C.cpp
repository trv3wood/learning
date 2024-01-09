/*有n 个玩家围成一圈，并按1到n编号。
现从第1个玩家开始从1开始依次递增报数，
报得的序号为素数的玩家出圈，直至所有玩家出圈。
现需要确定出圈的顺序，请编程解决该问题。
输入
1个int，表示n个玩家
输出
n个int，表示出圈顺序
样例输入 Copy
3
5
7
样例输出 Copy
2 3 1 
2 3 5 4 1 
2 3 5 7 1 6 4*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime (int n) {
    if(n == 1)
        return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

int main() {
    int n;
    while(cin >> n) {
        vector<int> v;
        for(int i = 1; i <= n; i++)
            v.push_back(i);//初始化

        int cnt = 0;//报数
        while(v.size() > 1) {//只剩一个人时退出循环
            for(int i = 0; i < v.size(); i++) {//遍历
                if(isPrime(++cnt)) {//报数
                    cout << v[i] << " ";//输出
                    v.erase(v.begin() + i);//删除
                    i--;//避免越界
                }
            }
        }
        cout << v[0] << endl;//输出最后一个人
    }
}
