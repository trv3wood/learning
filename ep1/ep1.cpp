#include <iostream>
using namespace std;
// 计算利润提成
int main() {
  double profit, bonus;
  while (cin >> profit) {
    double bonus = 0;
    if (profit >= 0 && profit <= 10) {
      bonus = profit * 0.1;
    } else if (profit >= 0 && profit <= 20) {
      bonus = 10 * 0.1 + (profit - 10) * 0.075;
    } else if (profit >= 0 && profit <= 40) {
      bonus = 10 * 0.1 + 10 * 0.075 + (profit - 20) * 0.05;
    } else if (profit >= 0 && profit <= 60) {
      bonus = 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + (profit - 40) * 0.03;
    } else if (profit >= 0 && profit <= 100) {
      bonus =
          10 * 0.1 + 10 * 0.075 + 20 * 0.05 + 20 * 0.03 + (profit - 60) * 0.015;
    } else if (profit >= 0 && profit > 100) {
      bonus = 10 * 0.1 + 10 * 0.075 + 20 * 0.05 + 20 * 0.03 + 40 * 0.015 +
              (profit - 100) * 0.01;
    }
    cout << bonus << endl;
    bonus = 0;
  }
}