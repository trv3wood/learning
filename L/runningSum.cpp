#include <iostream>
#include <vector>
class Solution {
public:
  int add = 0;
  std::vector<int> runningSum(std::vector<int> &nums) {
    std::vector<int> Sum ={};
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i+1; j++) {
        int a =nums[j];
        add += a;
      }
      Sum.push_back(add);
      add = 0;
    }
  return Sum;
  }
};

int main() {
  Solution s;
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> Sum = s.runningSum(nums);
  for (int i = 0; i < Sum.size(); ++i) {
    std::cout << Sum[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}