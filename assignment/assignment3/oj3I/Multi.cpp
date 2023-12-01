#include "combinatorics.h"
//Multi函数实现了阶乘的功能
int Multi(int m, int n) {
    int result = 1;
    for (int i = n; i <= m; i++) {
        result *= i;
    }
    return result;
}