//已知计算成绩的平均值和均方差公式分别为： ave ＝ 和 dev=
//人数n， Si 为第 i 个学生的成绩。求某班学生的平均成绩和均方差。
//输入：第一行为人数n，第二行为n个学生的成绩。
#include <bits/stdc++.h>
using namespace std;

float ave(vector<float> &v) {
    float sum = 0;
    for(float num : v) {
        sum += num;
    }
    return sum / v.size();
}

float dev(vector<float> &v) {
    float sum = 0;
    float average = ave(v);
    for(float num : v) {
        sum += (num - average) * (num - average);
    }
    return sqrt(sum / v.size());
}
//float ave(vector<float> &v) {
    //float sum = accumulate(v.begin(), v.end(), 0.0);
    //return sum / v.size();
//}

//float dev(vector<float> &v) {
    //float average = ave(v);
    //float sum = accumulate(v.begin(), v.end(), 0.0, [average](float acc, float num) {
        //return acc + pow(num - average, 2);
    //});
    //return sqrt(sum / v.size());
//}
int main() {
    int m;
    while(cin >> m) {
        vector<float> scores(m);
        for(int i = 0; i < m; i++) {
            cin >> scores[i];
        }
        cout << ave(scores) << " " << dev(scores) << endl;
    } 
}
    