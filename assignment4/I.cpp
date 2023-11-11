/*设计函数求一个整型数组的最小元素及其下标。
在主函数中定义和初始化该整型数组，
调用该函数并显示最小元素值和下标值。
输入
整形数组的长度以及整形数组的元素
输出
最小元素值和下标值
样例输入 Copy
5
1 2 3 4 5
5
9 5 6 8 2
样例输出 Copy
1 0
2 4*/
#include <bits/stdc++.h>
using namespace std;

void findMinElement(vector<int> nums) {
    int idx = 0;
    for(int i = 0; i < nums.size(); i++)
        if(nums[idx] > nums[i])
            idx = i;
    cout << nums[idx] << " " << idx << endl;
}
int main() {
    int size;
    while(cin >> size) {
        vector<int> nums(size);
        for(int i = 0; i < size; i++)
            cin >> nums[i];
        findMinElement(nums);
    }
}