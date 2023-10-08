#include <iostream>
using namespace std;

int main() {
  int year, month, day = 0;
  while (cin >> year >> month >> day) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;
    for (int i = 1; i <= month - 10; i++) {
      sum += days[i + 9];
    }
    sum += day;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      if (month > 2) {
        sum++;
      }
    }
    int weekday = sum % 7;
    if (weekday == 0)
      cout << 7 << endl;
    else
    cout<<weekday<<endl;
  }
  return 0;
}