#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 1. Two Sum(https://leetcode.com/problems/two-sum/)
// to find the index of two numbers that add up to a target
// solved by double pointer
class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target){
        vector<int> index(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            index[i] = i;
        }
        
        sort(index.begin(),index.end(),[&](int i,int j){
            return nums[i] < nums[j];
        });

        int head = 0;int tail = nums.size() - 1;
        
        while(head<tail){
            if(nums[index[head]] + nums[index[tail]] < target){
                head++;
            }
        
            if(nums[index[head]] + nums[index[tail]] > target){
                tail--;
            }
            if(nums[index[head]] + nums[index[tail]] == target){
                return {index[head],index[tail]};
            }
        }
        return {}; // add this line to fix the warning
    }
};
int main(){
    vector<int> nums = { 3,3 };
    int target = 6;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}