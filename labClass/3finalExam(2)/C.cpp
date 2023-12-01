/*疫情期间，为了控制疫情发展，经常要进行新冠病毒检测。某次参加新冠病毒检测的有学生、在职职工和退休人员，
现需计算这些人员之间的最小年龄差和最大年龄差。假设已知参与排队的人数和每个人的年龄。（多组测试数据）
输入
人数，每人的年龄（中间空空格隔开）                      （队伍的人数， 输完换行：Enter） （队伍中每个人的年龄，空格隔开，输完换行）
输出
输出两个数字，分别表示最小年龄差和最大年龄差
样例输入 Copy
10  
15 20 23 10 40 17 28 65 71 55 
15             
9 17 70 22 30 64 38 27 45 59 77 69 80 12 50
5              
80 40 12 25 62
样例输出 Copy
2  61
1  71
13  68
提示
建议使用数组存储数据*/
#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    while(cin >> n) {
        vector<int> ages(n);
        for(int i = 0; i < n; i++) {
            cin >> ages[i];
        }
        sort(ages.begin(), ages.end());

        int Min = INT_MAX;
        for(int i = 0; i < n - 1; i++) {
            Min = min(Min, ages[i + 1] - ages[i]);
        }
        int Max = ages[n - 1] - ages[0];
        cout << Min << " " << Max << endl;
    }
}