/*某班学生学号按入学考试成绩由高到低从1到n(n为人数)编号。
现期末考试成绩已统计好，老师欲分析每位同学的进、退步情况，请你编程解决该问题。
输入
一个int和一个char，
第1行：一个int n，表示学生人数（n<99）
第2行：n个int，表示按学号升序排列的n 个学生的期末考试成绩
输出
n个int，按学号顺序表示的每位同学的进、退步名次（为负表示退步、为正表示进步、为0表示既没有进步也没有退步）
样例输入 Copy
3 
99 98 92
4
91 92 92 94
6
90 95 96 93 92 94
样例输出 Copy
0 0 0
-3 0 1 3
-5 0 2 0 0 3*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int num;
    while(cin >> num) {
        vector<int> Scores(num);
        for(int i = 0; i < num; i++)
            cin >> Scores[i];

        vector<int> order(num, 0);
        for(int i = 0; i < num; i++)
            for(int j = 0; j < num; j++)
                if(Scores[i] < Scores[j])
                    order[i]++;
        for(int i = 0; i < num; i++)
            cout << i - order[i] << " ";
        cout << endl;
    }
}