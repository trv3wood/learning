#include <iostream>
#include <vector>
#include <algorithm>
//给定一个数字数组，其中只有两个数字出现一次，其他数字都出现两次，找出这个数字
//方法1：排序，然后遍历，找到只出现一次的数字
class Solution {
public:
    std::vector<int> onceNum(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        std::vector<int> onceNumber;
        while(nums.size()>0){
            int target = nums[0] ;
            nums.erase(nums.begin());
            auto it = std::find(nums.begin(),nums.end(),target);
            if(it != nums.end()) {
                nums.erase(remove(nums.begin(),nums.end(),target));
            }else {
                onceNumber.emplace_back(target);
            }
        }
        return onceNumber;
    }
};
int main() {
    Solution sol;
    std::vector<int> nums = {0,1};
    auto onceNumber = sol.onceNum(nums);
    for(int i = 0;i < onceNumber.size(); ++i){
        std::cout << onceNumber[i] << " ";
    }
}