/*把某班学生的姓名和学号分别存放到两个数组中，
从键盘输入某位学生的学号，查找该学生是否在该班中，
若找到该学生，则显示出相应的姓名。
注意：两个数组是：// 学生姓名数组
char name[5][20] = { "li ming", "zhang qing", "liu xiao ping", "wang yin", "lu pei" };
// 学生编号数组
long num[5] = { 20030001, 20030002, 20030005, 20030007, 20030010 };

输入
一个学生的学号
输出
如果找到，则输出该学生的姓名
如果未找到，则输出：未找到该学生的信息。

样例输入 Copy
2003005
20030005
样例输出 Copy
未找到该学生的信息。
liu xiao ping*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, char*> map;
    char name[5][20] = { "li ming", "zhang qing", "liu xiao ping", "wang yin", "lu pei" };
    long num[5] = { 20030001, 20030002, 20030005, 20030007, 20030010 };
    for(int i = 0; i < 5; i++)
        map[num[i] - 20030001] = name[i];
    long n;
    while(cin >> n) {
        if(n - 20030001 < 0 || n - 20030001 > 10)
            cout << "未找到该学生的信息。" << endl;
        else
            if(map.count(n - 20030001))
                cout << map[n - 20030001] << endl;
            else
                cout << "未找到该学生的信息。" << endl;
    }
}