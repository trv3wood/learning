#include <iostream>
#include "combinatorics.h"

int main() {
    int m, n;
    std::cin >> m >> n;
    std::cout << Fabricate(m, n) << std::endl;
    return 0;
}