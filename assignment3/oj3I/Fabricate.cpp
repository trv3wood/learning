#include "combinatorics.h"

int Fabricate(int m, int n) {
    if (m < n) {
        return 0;
    }
    return Multi(m, m - n + 1) / Multi(n, 1);
}