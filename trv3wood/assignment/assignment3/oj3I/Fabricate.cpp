#include "combinatorics.h"
//多文件编程示例，Fabricate函数在combinatorics.h中声明，在Fabricate.cpp中实现
//Fabricate函数实现了排列的功能
int Fabricate(int m, int n) {
    if (m < n) {
        return 0;
    }
    return Multi(m, m - n + 1) / Multi(n, 1);
}