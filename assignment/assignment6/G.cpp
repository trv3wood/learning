/*把一个班的学生姓名和成绩存放到一个结构数组中，寻找并输出最高分者。
班级的姓名和成绩为：
{"李小平", 90},
 {"何文章", 66},
 {"刘大安", 87},
 {"江立新", 93},
 {"罗建国", 72},
 {"陆丰收", 81},
 {"杨勇", 85},
 {"昊一兵", 55},
 {"伍晓笑", 68},
 {"张虹虹", 93}
输入
无
输出
得分最高的学生姓名和成绩（注意，如果存在多个人，则一个同学的姓名和成绩占一行，姓名和成绩之间使用一个空格间隔）*/
#include <bits/stdc++.h>
using namespace std;

struct scoresList {
    string name;
    int score;
};

int main() {
    vector<scoresList> list = {
        {"李小平", 90},
        {"何文章", 66},
        {"刘大安", 87},
        {"江立新", 93},
        {"罗建国", 72},
        {"陆丰收", 81},
        {"杨勇", 85},
        {"昊一兵", 55},
        {"伍晓笑", 68},
        {"张虹虹", 93}
    };
    int highestScore = 0;
    vector<scoresList> nameList;
    for(int i = 0; i < 10; i++) {
        highestScore = max(highestScore, list[i].score);
    }
    for(int i = 0; i < 10; i++) {
        if(list[i].score == highestScore)
            nameList.emplace_back(list[i]);
    }
    for(scoresList person : nameList)
        cout << person.name << " " << person.score << endl;
}