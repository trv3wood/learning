//已知计算成绩的平均值和均方差公式分别为： ave ＝ 和 dev=
//人数n， Si 为第 i 个学生的成绩。求某班学生的平均成绩和均方差。
//输入：第一行为人数n，第二行为n个学生的成绩。
#include <bits/stdc++.h>
using namespace std;

double ave(vector<double> &v) {
    double sum = 0;
    for(double num : v) {
        sum += num;
    }
    return sum / v.size();
}

double dev(vector<double> &v) {
    double sum = 0;
    double average = ave(v);
    for(double num : v) {
        sum += (num - average) * (num - average);
    }
    return sqrt(sum / v.size());
}
//double ave(vector<double> &v) {
    //double sum = accumulate(v.begin(), v.end(), 0.0);
    //return sum / v.size();
//}

//double dev(vector<double> &v) {
    //double average = ave(v);
    //double sum = accumulate(v.begin(), v.end(), 0.0, [average](double acc, double num) {
        //return acc + pow(num - average, 2);
    //});
    //return sqrt(sum / v.size());
//} 
int main() {
    int n;
    while(cin >> n) {
        vector<double> v(n);
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        cout << ave(v) << " " << dev(v) << endl;
    }
    return 0;
}