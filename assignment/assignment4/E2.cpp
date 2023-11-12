/*写一个合并函数，把两个升序排列的数组合井为一个升序数组。
生成两个不等长有序数组测试合并函数。请分别用数组或vector类实现。
输入
两个数组的个数以及数组元素
输出
合并的升序数组元素（一个空格间隔）
样例输入 Copy
5 6
1 2 3 4 5 1 2 3 4 5 6
4 6
12 15 16 19 23 26 59 100 120 150
样例输出 Copy
1 1 2 2 3 3 4 4 5 5 6
12 15 16 19 23 26 59 100 120 150*/
#include <bits/stdc++.h>
using namespace std;

void combine(vector<int> v1, vector<int> v2) {
    int Max = max(v1.back(), v2.back());
    int Min = min(v1[0], v2[0]);

    int *bucket = new int[Max - Min + 1];
    memset(bucket, 0, (Max - Min + 1) * sizeof(int));
    for(int num : v1)
        bucket[num - Min]++;
    for(int num : v2)
        bucket[num - Min]++;
    
    vector<int> combinedVector;
    for(int i = 0; i <= Max - Min; i++){
        while(bucket[i] > 0) {
            combinedVector.emplace_back(i + Min);
            bucket[i]--;
        }
    }
    for(int num : combinedVector)
        cout << num << " ";
}

int main() {
    int n, m;
    while(cin >> n >> m) {
        vector<int> v1(n), v2(m);
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> v2[i];
        }
        combine(v1, v2);
        cout << endl;
    }
    return 0;
}