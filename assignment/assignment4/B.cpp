//用随机函数产生 10 个互不相同的两位整数存放到一维数组中，并输出其中的素数。
#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));//设置随机数种子
    vector<int> nums;
    for(int i = 0; i < 10; i++) {
        int num = rand() % 90 + 10;//产生 10 到 99 之间的随机数
        nums.push_back(num);
    }
    
    for(int num : nums) {
        bool isPrime = true;
        for(int i = 2; i < num; i++) {
            if(num % i == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            cout << num << " ";
        }
    }
    cout << endl;
}