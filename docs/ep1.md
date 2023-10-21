# 第一次实验课上机题目

## 目录

- ep1
    - [A 计算利润提成](#A)
    - [B 3+33+333](#B)
    - [C 小球反弹](#C)
    - [D 计算星期几](#D)
    - [E 打印阶梯型](#E)

## A

```cpp
#include <iostream>
using namespace std;
//计算利润提成
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
```
[返回目录](#目录)
## B

```cpp
#include <iostream>
using namespace std;
//计算利润提成
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
```
[返回目录](#目录)
## B
```cpp
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
```
[返回目录](#目录)
## C

```cpp
#include <iostream>
#include <iomanip>
using namespace std;
//correct
int main(){
    int h;
    while(cin>>h){
        double height = h * 1000;
        double S = height;
        int n = 0;
        while(height >= 1){
            height *= 0.5;
            S += 2 * height;
            n += 1;
        }
        cout<< n <<" "<<setprecision(4)<<fixed<< S *0.001<<endl;
    }
}
```
[返回目录](#目录)
## D

```cpp
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
  if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
      days[1]=29;
      for(int i = 0; i < month - 1; ++i) {
        sum += days[i];
    }
  }else{
      for(int i = 0; i < month - 1; ++i) {
        sum += days[i];
  }
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
```
[返回目录](#目录)
## E
*打印*
```cpp
#include <iostream>
using namespace std;
//过了！！！！！
int main() {
    char ch;
    int n;
    while (cin >> ch >> n) {
        for(int j = 1 ; j<=n ;++j){
            for(int i = 1; i<=j;i++){
                for (int x = 1; x <= n - i; x++) {
                    cout << " ";
                }
                for (int x = 1; x <= 2 * i - 1; x++) {
                    cout << ch;
                }
            cout<<endl;
            }
        }
    }
}
```
[返回目录](#目录)