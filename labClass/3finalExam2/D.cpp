/*给定一幅大小为m×n个像素点的黑白图像，请编写程序将图像朝顺时钟方向旋转90度、180度或270度。
如图像：


输入
第一行：2个int： m（行）和n（列），m*n < 9999
第二行：m×n个bool，表示图像的m×n个像素点的值（0表示白色、1表示黑色），以行为主序输入。
第三行：1个整数，表示旋转的角度

输出
m行，n列，表示旋转以后的图像像素值
样例输入 Copy
2 2
1 0 0 1
90
4 3
1 0 1 1 0 1 1 1 0 0 1 0
180
row 
样例输出 Copy
0 1
1 0
0 1 0
0 1 1
1 0 1
1 0 1*/
#include <bits/stdc++.h>
using namespace std;
int row; int col;
int angle;
int main() {
    while(cin >> row >> col) {
        vector<vector<int>> img(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                cin >> img[i][j];
            }
        }
        cin >> angle;
        if(angle == 90) {
            for(int i = 0; i < col; i++) {
                for(int j = row - 1; j >= 0; j--) {
                    cout << img[j][i] << " ";
                }
                cout << endl;
            }
        } else if(angle == 180) {
            for(int i = row - 1; i >= 0; i--) {
                for(int j = col - 1; j >= 0; j--) {
                    cout << img[i][j] << " ";
                }
                cout << endl;
            }
        } else if(angle == 270) {
            for(int i = col - 1; i >= 0; i--) {
                for(int j = 0; j < row; j++) {
                    cout << img[j][i] << " ";
                }
                cout << endl;
            }
        }
    }
}