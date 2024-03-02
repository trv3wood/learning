#include <iostream>
using namespace std;
//use zeller formula
int getDayOfWeek(int year, int month, int day) {
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    int century = year / 100;
    year %= 100;
    int week = year + year / 4 + century / 4 - 2 * century + 26 * (month + 1) / 10 + day - 1;
    week = (week % 7 + 7) % 7;
    return week;
}
int main(){
    int year, month, day;
    while(cin >> year >> month >> day)
        if(getDayOfWeek(year, month, day) == 0)
            cout << 7 << endl;
        else
            cout << getDayOfWeek(year, month, day) << endl;
    return 0;
}