#include <iostream>
#include <vector>
#include <algorithm>
//求三个数最大值和最小值
//要求：把求最值的操作分别编写成两个函数，
//并使用指针或引用作为形式参数，把结果返回main函数
int Maximum(std::vector<int>& nums){
    std::vector<int>::iterator result =
    std::max_element(nums.begin(),nums.end());
    int max = *result;
    return max;
}
int Minimum(std::vector<int>& nums){
    std::vector<int>::iterator result =
    std::min_element(nums.begin(),nums.end());
    int min = *result;
    return min;
}

int main(){
    std::vector<int> nums = {4,2,6,4,23,7};
    std::cout << Maximum(nums) << std::endl;
    std::cout << Minimum(nums) << std::endl;
    return 0;
}