#include <iostream>
#include <unordered_map>
#include <vector>

int searchInsert(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> hash;
  for (int i = 0; i < nums.size(); ++i) {
    hash[nums[i]] = i;
  }
  if (hash.count(target)) {
    int result = hash[target];
    return result;
  } else
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < target && nums[i + 1] > target) {
        return i + 1;
      }
    }
  return -1;
}
int main() {
  std::vector<int> nums = {1, 3, 5, 6};
  int target = 2;
  int result = searchInsert(nums, target);
  std::cout << result;
  return 0;
}