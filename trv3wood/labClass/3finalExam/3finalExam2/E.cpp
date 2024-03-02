/*给定一个已排序（从小到大）的数组，求数组中是否存在两个元素之和为某个值。例如，给定数组{1，4，4，7}，
指定sum为11，存在元素4和7使得两数之和为11，返回结果“TRUE”。仍对该数组，若指定sum为15，则返回“FASLSE”
输入
输入：多组数据。每组输入3行，依次代表数组长度，数组元素、所给定要判断的和。例如：
4
1 4 4 7
11
5
1 3 5 5 10
16
输出
输出：N组结果。对示例输入，有：
“TRUE”
“FALSE”
样例输入 Copy
4
1，4，4，7
11
5
1，3，5，5，10
16*/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    //双指针
    string twoSum(vector<int>& nums,int target){
        vector<int> index(nums.size());
        
        int head = 0;int tail = nums.size() - 1;
        
        while(head < tail){
            if(nums[head] + nums[tail] < target){
                head++;
            }
        
            if(nums[head] + nums[tail] > target){
                tail--;
            }
            if(nums[head] + nums[tail] == target){
                return "TRUE";
            }
        }
        return "FALSE";
    }
};
int n;
int target;
int main(){
    Solution sol;
    while(cin >> n) {
        vector<int> nums(n);
        for(int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        cin >> target;
        cout << sol.twoSum(nums, target) << endl;
    }
}