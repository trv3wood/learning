#include <iostream>
using namespace std;
//getdayofweek(own),过了
int getDayOfWeek(int year, int month, int day) {
  int sum = 0;
  for (int i = 1; i < year; ++i) {
    if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
      sum += 366;
    } else
      sum += 365;
  }
  int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  for(int i = 0; i < month - 1; ++i) {
    sum += days[i];
  }
  sum+=day;
  int weekday = sum % 7;
  return weekday;
}
int main() {
  int year, month, day = 0;
  while (cin >> year >> month >> day) {
    if(getDayOfWeek(year, month, day) == 0)
      cout << 7 << endl;
    else
      cout << getDayOfWeek(year, month, day) << endl;
  }
  return 0;
}