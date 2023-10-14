#include <iostream>
using namespace std;
//终于~过了~
int calculate(int &n, int &x) {
  int digit = x;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += digit;
    digit *= 10;
  }
  return sum;
};
long long add(int& n,int& x) {
  long long result = 0;
  for (int i = 1; i < n + 1;i++) {
    result += calculate(i,x);
  }
  return result;
};

int main() {
  int n, x;
  while (cin >> x >> n) {
    cout << add(n, x)<< endl;
  }
  return 0;
}

