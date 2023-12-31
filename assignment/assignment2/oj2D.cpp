#include <iostream>
using namespace std;
// 提取整数的素数因子
bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
};
int main() {
  int num;
  while (cin >> num) {
    if (isPrime(num))
      cout << num << " ";
    else
      for (int i = 2; i <= num; i++) {
        while (isPrime(i) && num % i == 0) {
          cout << i << " ";
          num = num / i;
        }
      }
  }
}