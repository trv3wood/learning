#include <iostream>
using namespace std;

int daygone(int year,int month,int day){
    int sum = 0;
    for(int i = 1;i < year+1;++i){
      if(i%4==0&&i%100!=0||i%400==0){
        sum+=366;
      }
      else
        sum+=365;
    }
    int days[]={31,28,31,30,31};
}
int main() {
  int year, month, day = 0;
  while (cin >> year >> month >> day) {
    

  }
    return 0;
}