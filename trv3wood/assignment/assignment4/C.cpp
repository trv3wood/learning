//将一组数据从大到小排列后输出，要求显示每个元素及它们在原数组中的下标。
#include <bits/stdc++.h>
using namespace std;
//解法1
void listSort(vector<int> &v) {
    unordered_map<int, int> map;
    for(int i = 0; i < v.size(); i++) {
        map[v[i]] = i;
    }
    sort(v.begin(), v.end(), [&](int a, int b) {return a > b;});
    for(int num : v) {
        cout << num << " " << map[num] << endl;
    }
}
//桶排序
void listSort2(int arr[]) {
    int max = arr[0];//找到最大值和最小值
    int min = arr[0];
    for(int i = 1; i < 5; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    //创建桶
    int *bucket = new int[max - min + 1];

    //桶初始化
    memset(bucket, 0, (max - min + 1) * sizeof(int));
    
    //将数据放入桶中
    for(int i = 0; i < 5; i++) {
        bucket[arr[i] - min]++;
    }
    //从桶中取出数据
    for(int i = max - min; i >= 0; i--) {
        while(bucket[i] > 0) {
            cout << i + min << "\t";
            bucket[i]--;
        }
    }
    cout << endl;
}
//选择排序(to do),从大到小，输出原下标

int main() {
    int num;
    while(cin >> num) {
        vector<int> nums(num);
        for(int i = 0; i < num; i++) {
            cin >> nums[i];
        }
        listSort(nums);
    }
    return 0;
}