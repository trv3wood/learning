/*个人所得税税率是这样的：月工资在1-5000元之间的，税率为0%；在5000-8000元之间的，包含8000元，
税率为3%；在8000-17000元之间的，含17000元，税率为10%；在17000-30000元之间的，含30000元，税率为20%；在30000-40000元之间的，
含40000元，税率为25%；在40000-60000元之间的，含60000元，税率为30%；工资范围在60000-85000元之间的，含85000元，税率为35%；
在85000元以上的，税率为45%。编写程序，统计一个单位某月缴纳的个人所得税总和和实际纳税的人数。（注意以上区间均为左开右闭）
输入
人数，每个人的月工资（空格隔开）（人数， 输完换行：Enter）（每个人的工资，空格隔开，输完换行）
输出
输出两个数字，分别代表个人所得税总和(精确到小数点后两位）和实际纳税人数。
样例输入 Copy
5
3000 5000 8000 30000 75000 
10									
5000  8500  13600  7800  25000 30000 4500 8600 3800 40000 
样例输出 Copy
21020 3
13294 7*/
#include <bits/stdc++.h>
using namespace std;

int n;
double tax(int num) {
    if(num > 1 && num <= 5000) {
        return 0;
    } else if(num > 5000 && num <= 8000) {
        return (num - 5000.0) * 0.03;
    } else if(num > 8000 && num <= 17000) {
        return 3000.0 * 0.03 + (num - 8000.0) * 0.1;
    } else if(num > 17000 && num <= 30000) {
        return 3000.0 * 0.03 + (17000.0 - 8000.0) * 0.1 + (num - 17000.0) * 0.2;
    } else if(num > 30000 && num <= 40000) {
        return 3000.0 * 0.03 + (17000.0 - 8000.0) * 0.1 + (30000.0 - 17000.0) * 0.2 + (num - 30000.0) * 0.25;
    } else if(num > 40000 && num <= 60000) {
        return 3000.0 * 0.03 + (17000.0 - 8000.0) * 0.1 + (30000.0 - 17000.0) * 0.2 + (40000.0 - 30000.0) * 0.25 + (num - 40000.0) * 0.3;
    } else if(num > 60000 && num <= 85000) {
        return 3000.0 * 0.03 + (17000.0 - 8000.0) * 0.1 + (30000.0 - 17000.0) * 0.2 + (40000.0 - 30000.0) * 0.25 + (60000.0 - 40000.0) * 0.3 +
        (num - 60000.0) * 0.35;
    } else if(num > 85000) {
        return 3000.0 * 0.03 + (17000.0 - 8000.0) * 0.1 + (30000.0 - 17000.0) * 0.2 + (40000.0 - 30000.0) * 0.25 + (60000.0 - 40000.0) * 0.3 +
        (85000.0 - 60000.0) * 0.35 + (num - 85000.0) * 0.45;
    }
    return 0;
}
int main() {
    while(cin >> n) {
        vector<int> salarys(n);
        for(int i = 0; i < n; i++) {
            cin >> salarys[i];
        }
        int cnt = 0;
        double sum = 0;
        for(int i = 0; i < salarys.size(); i++) {
            if(salarys[i] > 5000)
                cnt++;
            sum += tax(salarys[i]);
        }
        cout << sum << " ";
        cout << cnt << endl;
    }
}