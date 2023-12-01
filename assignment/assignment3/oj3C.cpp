#include <iostream>
//猜数
//给定一个整数n，代表猜数的范围为[0,n]，每次猜数系统会给出一个反馈，
//1代表猜大了，-1代表猜小了，0代表猜对了。
//二分法
void guess(int& feedback, int& left, int& right) {
    if(feedback == 1) {
        right = (left + right) / 2;
        std::cout << (left + right) / 2 << std::endl;
    } else if(feedback == -1) {
        left = (left + right) / 2;
        std::cout << (left + right) / 2 << std::endl;
    }
}

int main() {
    std::cout << 500 << std::endl;
    int feedback, n = 0;
    int left = 0; int right = 1000;
    while (std::cin >> feedback) {
        guess(feedback, left, right);
        n++;
        if(feedback == 0) {
            std::cout << "猜了" << n << "次" << std::endl;
            return 0;
        }
    }
    return 0;
}