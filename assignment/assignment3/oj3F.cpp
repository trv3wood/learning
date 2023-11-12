#include <iostream>

// 把循环函数修改为等价的递归函数

void print(int w, int row = 1, int column = 1) {
    if (row > w) {
        return;
    }
    std::cout << row << " ";
    if (column == row) {
        std::cout << std::endl;
        print(w, row + 1, 1);
    } else {
        print(w, row, column + 1);
    }
}

int main() {
    int w;
    print(5);
    return 0;
}