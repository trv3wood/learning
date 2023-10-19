#include "combinatorics.h"

int Multi(int m, int n) {
    int result = 1;
    for (int i = n; i <= m; i++) {
        result *= i;
    }
    return result;
}