#include <bits/stdc++.h>
//给你一个整数 num ，返回 num 中能整除 num 的数位的数目。
//如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。
class Solution {
public:
    int countDigits(int num) {
        int count = 0;
        int numCopy = num;
        while(num > 0) {
            int tmp = num % 10;
            if(numCopy % tmp == 0) {count++;}
            num /= 10;
        }
    return count;
    }
};
int main() {
    Solution s;
    std::cout << s.countDigits(121) << std::endl;
    return 0;
}