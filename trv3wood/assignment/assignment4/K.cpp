/*一个整型数组的每个元素占 4 字节。编写一个压缩函数 pack，
把一个无符号小整数 (0-255)数组进行压缩存储，只存放低 8 位;
再编写一个解压函数 upack，把压缩数组展开，以整数形式存放。
主函数手动输入数据以初始化数组，（注意使用动态数组），测试 pack 和 unpack 函数
输入
一个数组的长度及数组元素
输出
压缩前和压缩后的数组
样例输入 Copy
5
1 2 3 4 5
15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
样例输出 Copy
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15*/
#include <bits/stdc++.h>
using namespace std;
int *pack(int *a, int n, int &m) {
    m = n;
    int *b = new int[m];
    for (int i = 0; i < n; i++) {
        //取低8位
        b[i] = a[i] & 0xff;
        //高于8位的置0
        //低于8位的不变
    }
    return b;
}
int* unpack(int *a, int n, int &m) {
    m = n;
    int *b = new int[m];
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
    return b;
}

int main() {
    int n, m;
    while(cin >> n) {
        int *a = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int *b = pack(a, n, m);
        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
        int *c = unpack(b, m, n);
        for (int i = 0; i < n; i++) {
            cout << c[i] << " ";
        }
        cout << endl;
    }
    return 0;
}