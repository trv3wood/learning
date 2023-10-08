#include <iostream>
using namespace std;
//好像没什么问题  
int calculate(int &n, int &x) {
  int digit = x;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += digit;
    digit *= 10;
  }
  return sum;
};
int add(int& n,int& x) {
  int result = 0;
  for (int i = 1; i < n + 1;i++) {
    result += calculate(i,x);
  }
  return result;
};

int main() {
  int n, x;
  while (cin >> n >> x) {
    cout << add(n, x);
  }
  return 0;
}

