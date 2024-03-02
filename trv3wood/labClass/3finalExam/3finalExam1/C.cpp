/*给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。找出其中的两条线，
使得它们与 x 轴共同构成的容器可以容纳最多的水。返回容器可以储存的最大水量。
输入
多组数据
每组包含数组长度和数组数据.
输出
容器最大的储水量。
样例输入 Copy
9
1 8 6 2 5 4 8 3 7
3
2 1 2
样例输出 Copy
49
4
提示
使用函数求解，函数接受一个数组和数组长度作为参数，返回答案*/
#include <bits/stdc++.h>
using namespace std;

//求最大容量
int maxCapability(vector<int> heights) {
    int Max = 0;
    for(int i = 0; i < heights.size(); i++) {
        for(int j = 0; j < heights.size(); j++) {
            //tmp为两个高度中较小的那个
            int tmp = min(heights[i], heights[j]);

            //curCapability为当前容量
            int curCapability;
            if(i < j) {
                curCapability = (j - i) * tmp;
            } else {
                curCapability = (i - j) * tmp;
            }
            //更新最大容量
            Max = max(curCapability, Max);
        }
    }
    return Max;    
}
int main() {
    int len;
    while(cin >> len) {
        vector<int> heights(len);
        for(int i = 0; i < len; i++) {
            cin >> heights[i];
        }
        cout << maxCapability(heights) << endl;
    }
}