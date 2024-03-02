#include <iostream>
#include <vector>
#include <algorithm>
// 求三个数最大值和最小值
// 要求：把求最值的操作分别编写成两个函数，
// 并使用指针或引用作为形式参数，把结果返回main函数
float Maximum(std::vector<float> &nums) {
    std::vector<float>::iterator result =
        std::max_element(nums.begin(), nums.end());
    float max = *result;
    return max;
}
float Minimum(std::vector<float> &nums) {
    std::vector<float>::iterator result =
        std::min_element(nums.begin(), nums.end());
    float min = *result;
    return min;
}

int main() {
    float a, b, c;
    while (std::cin >> a >> b >> c) {
        std::vector<float> nums = {a, b, c};
        std::cout << "max = " << Maximum(nums)
                  << " min = " << Minimum(nums) << std::endl;
    }
    return 0;
}