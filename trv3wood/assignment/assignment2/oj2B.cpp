#include <iostream>
using namespace std;
// 模拟“剪刀、石头、布”游戏。
// 利用ASCII码判断
int main() {
  char a, b;
  while (cin >> a >> b) {
    int A = static_cast<int>(a);
    int B = static_cast<int>(b);
    if (A - B == 3)
      cout << "甲方胜" << endl;
    else if (A - B == 2)
      cout << "乙方胜" << endl;
    else if (A - B == 1)
      cout << "乙方胜" << endl;
    else if (A - B == -3)
      cout << "乙方胜" << endl;
    else if (A - B == -2)
      cout << "甲方胜" << endl;
    else if (A - B == -1)
      cout << "甲方胜" << endl;
    else if (A == B)
      cout << "平局" << endl;
  }
}