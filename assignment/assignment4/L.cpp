/*编写程序，输入一个数组，然后逆置该数组元素例如，
数组 A 的初值为{6,3,7,8,2)，逆置后的值为(2,8,7,3,6)。
要求: 输出逆置前、后的数组元素序列。
输入
一个数组的长度及其长度
输出
逆置前以及逆置后的元素序列
样例输入 Copy
5
9 8 6 5 1
10
1 2 3 4 5 6 7 8 9 10
样例输出 Copy
9 8 6 5 1
1 5 6 8 9
1 2 3 4 5 6 7 8 9 10
10 9 8 7 6 5 4 3 2 1*/

//方法：使用std::reverse函数
//才不会老老实实地写一个for循环逆置呢
#include <bits/stdc++.h>
using namespace std;

//模仿了std::reverse的实现
void myReverse(vector<int>& v) {
    auto first = v.begin();
    auto last = v.end() - 1;
    if(first == last) {
        return;
    }
    while(first < last) {
        iter_swap(first, last);
        first++;
        last--;
    }
    return;
}

int main() {
    int size;
    while(cin >> size) {
        vector<int> nums(size);
        for(int i = 0; i < size; i++)
            cin >> nums[i];
        for(int num : nums)
            cout << num << " ";
        cout << endl;
        myReverse(nums);
        //std::reverse(nums.begin(), nums.end());
        for(int num : nums)
            cout << num << " ";
        cout << endl;
    }
}