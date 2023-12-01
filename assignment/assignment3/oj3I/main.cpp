#include <iostream>
#include "combinatorics.h"
//多文件编程示例，在main.cpp中引用combinatorics.h中的函数
int main() {
    int m, n;
    std::cin >> m >> n;
    std::cout << Fabricate(m, n) << std::endl;
    return 0;
}