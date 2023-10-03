#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// 1. Two Sum(1) leetcode.com/problems/two-sum/
// to find the index of two numbers that add up to a target
// solved by hash table
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.count(complement)) {
                return { hash[complement], i };
            }
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;
    Solution sol;
    vector<int> result = sol.twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}