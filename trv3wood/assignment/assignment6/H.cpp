/*使用结构体表示X-Y平面直角坐标系上的点，编写程序，顺序读入一个四边形的4 个顶点坐标，
判别由这个顶点的连线构成的图形是否为正方形、矩形或其他四边形。要求: 定义求两个点距离的函数使用结构参数。
输入
四个点的坐标（double型的，注意需要按照顺时针或者逆时针的方向输入四个点的坐标）
输出
“矩形”或者“正方形”或者“其他四边形”
样例输入 Copy
0 0 1 0 2 2 3 0
0 0 1 0 1 1 0 1
1 1 1 2.5 3 2.5 3 0
1 1 1 2.5 3 2.5 3 1
样例输出 Copy
其他四边形
正方形
其他四边形
矩形*/
#include <bits/stdc++.h>
using namespace std;

struct position {
    double x;
    double y;
    position(double X, double Y) {
        x = X;
        y = Y;
    }
};

bool isParallel(position a, position b, position c, position d) {
    return (b.y - a.y) * (d.x - c.x) == (d.y - c.y) * (b.x - a.x);
}

bool isVertical(position a, position b, position c) {
    return (a.x - b.x) * (c.x - b.x) + (a.y - b.y) * (c.y - b.y) == 0;
}

double distance(position a, position b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
        position a(x1, y1), b(x2, y2), c(x3, y3), d(x4, y4);
        if(isParallel(a, b, c, d) && isParallel(b, c, d, a) && isParallel(c, d, a, b) && isParallel(d, a, b, c)) {
            if(isVertical(a, b, c) && isVertical(b, c, d) && isVertical(c, d, a) && isVertical(d, a, b)) {
                if(distance(a, b) == distance(b, c) && distance(b, c) == distance(c, d) && distance(c, d) == distance(d, a)) {
                    cout << "正方形" << endl;
                } else {
                    cout << "矩形" << endl;
                }
            } else {
                cout << "其他四边形" << endl;
            }
        } else {
            cout << "其他四边形" << endl;
        }
    }
    return 0;
}