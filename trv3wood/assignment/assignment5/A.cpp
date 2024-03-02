/*计算月龄
我们一般用年龄表示一个人的大小，但是也可以用月、周、天表示。
给定你的出生日期和指定日期，先计算日期有效性，
若日期无效，输出"invalid date!"，
若当前日期小于出生日期，输出"wrong enddate!"，
输出你的月龄（不足1月按1月计算）、周龄（不足1周按1周计算）和天龄，
输入
六个int，表示两个日期，一行一个日期
输出
三个int，表示月龄、周龄和天龄
样例输入 Copy
1900 2 29
2000 2 29
2000 12 30
2000 1 30
2000 2 29
2004 2 29
2000 2 29
2000 4 29
样例输出 Copy
invalid date!
wrong enddate!
49 209 1461
2 9 60
提示
闰年满足：年份能被4整除且不能被100整除 或者 能被400整除;一周=7天；一月=30天；*/

//重构代码，使用类
//感觉用类写的代码更加简洁，而且更加容易理解
#include <bits/stdc++.h>
using namespace std;

//定义一个日期类，包含年月日三个成员变量，以及一些成员函数
class Date {
public:
    int year, month, day;
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    Date() {}
public:
    //判断日期是否合法
    bool isValidDate() {
        if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            if(month > 0 && month <= 12) {
                if(month == 2) {
                    if(day > 0 && day <= 29)
                        return true;
                } else if(month <= 7) {
                    if(month % 2 != 0 && day > 0 && day <= 31)
                        return true;
                    else if(day > 0 && day <= 30)
                        return true;
                } else {
                    if(month % 2 == 0 && day > 0 && day <= 31)
                        return true;
                    else if(day > 0 && day <= 30)
                        return true;
                }
            }
        } else {
            if(month > 0 && month <= 12) {
                if(month == 2) {
                    if(day > 0 && day <= 28)
                        return true;
                } else if(month <= 7) {
                    if(month % 2 != 0 && day > 0 && day <= 31)
                        return true;
                    else if(day > 0 && day <= 30)
                        return true;
                } else {
                    if(month % 2 == 0 && day > 0 && day <= 31)
                        return true;
                    else if(day > 0 && day <= 30)
                        return true;
                }
            }
        }
        return false;
    }
    //比较两个日期的大小
    //如果当前日期小于end，返回true，否则返回false
    //end是一个Date类的对象,代表结束日期，当前日期是调用该函数的对象
    bool cmpDates(Date &end) {
        if(year < end.year)
            return true;
        if(year > end.year)
            return false;
        else 
            if(month < end.month)
                return true;
            if(month > end.month)
                return false;
            else 
                if(day < end.day)
                    return true;
                if(day > end.day)
                    return false;
                else 
                    return true;
    }
    //计算日期距离公元元年的天数
    int getDaysOfDate() {
        int sum = 0;
        for (int i = 1; i < year; ++i) {
            if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
                sum += 366;
            } else
                sum += 365;
        }
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30,
                      31, 30, 31};
        if(year % 4 == 0 && year % 100 != 0 || year% 400 == 0){
            days[1]=29;
            for(int i = 0; i < month - 1; ++i)
                sum += days[i];
        }else{
            for(int i = 0; i < month - 1; ++i)
                sum += days[i];
        }
        sum += day;

        return sum;
    }
};

int main() {
    int year, month, day;
    while(cin >> year >> month >> day) {
        Date bornDate(year, month, day);
        cin >> year >> month >> day;
        Date presentDate(year, month, day);
        if(!bornDate.isValidDate() || !presentDate.isValidDate())
            cout << "invalid date!" << endl;
        else {
            if(!bornDate.cmpDates(presentDate))
                cout << "wrong enddate!" << endl;
            else {
                int days = presentDate.getDaysOfDate() - bornDate.getDaysOfDate();

                int months = days / 30;
                if(days % 30)
                    months++;
                cout << months << endl;

                int weeks = days / 7;
                if(days % 7)
                    weeks++;
                cout << weeks << endl;

                cout << days << endl;
            }
        }
    }
}

//enum date {
    //year = 0, month = 1, day = 2
//};

//bool isValidDate(int date[3]) {
    //if(date[year] % 4 == 0 && date[year] % 100 != 0 || date[year] % 400 == 0) {
        //if(date[month] > 0 && date[month] <= 12) {
            //if(date[month] == 2) {
                //if(date[day] > 0 && date[day] <= 29)
                    //return true;
            //} else if(date[month] <= 7) {
                //if(date[month] % 2 != 0 && date[day] > 0 && date[day] <= 31)
                    //return true;
                //else if(date[day] > 0 && date[day] <= 30)
                    //return true;
            //} else {
                //if(date[month] % 2 == 0 && date[day] > 0 && date[day] <= 31)
                    //return true;
                //else if(date[day] > 0 && date[day] <= 30)
                    //return true;
            //}
        //}
    //} else {
        //if(date[month] > 0 && date[month] <= 12) {
            //if(date[month] == 2) {
                //if(date[day] > 0 && date[day] <= 28)
                    //return true;
            //} else if(date[month] <= 7) {
                //if(date[month] % 2 != 0 && date[day] > 0 && date[day] <= 31)
                    //return true;
                //else if(date[day] > 0 && date[day] <= 30)
                    //return true;
            //} else {
                //if(date[month] % 2 == 0 && date[day] > 0 && date[day] <= 31)
                    //return true;
                //else if(date[day] > 0 && date[day] <= 30)
                    //return true;
            //}
        //}
    //}
    //return false;
//}

//bool cmpDates(int born[], int end[], int i = 0) {
    
    //if(i > 2)
        //return true;
    //else 
        //if(born[i] < end[i])
            //return true;
        //if(born[i] > end[i])
            //return false;
        //else 
            //return cmpDates(born, end, i + 1); 
//}
//int getDaysOfDate(int date[]) {
    //int sum = 0;
    //for (int i = 1; i < date[year]; ++i) {
        //if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
            //sum += 366;
        //} else
            //sum += 365;
    //}
    //int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //if(date[year] % 4 == 0 && date[year] % 100 != 0 || date[year]% 400 == 0){
        //days[1]=29;
        //for(int i = 0; i < date[month] - 1; ++i)
            //sum += days[i];
    //}else{
        //for(int i = 0; i < date[month] - 1; ++i)
            //sum += days[i];
    //}
    //sum += date[day];

    //return sum;
//}

//int main() {
    //int bornDate[3],presentDate[3];
    //while(cin >> bornDate[year] >> bornDate[month] >> bornDate[day]) {
        //cin >> presentDate[year] >> presentDate[month] >> presentDate[day];
        //if(!isValidDate(bornDate) || !isValidDate(presentDate))
            //cout << "invalid date!" << endl;
        //else 
            //if(!cmpDates(bornDate, presentDate))
                //cout << "wrong enddate!" << endl;
            //else {
                //int days = getDaysOfDate(presentDate) - getDaysOfDate(bornDate);

                //int months = days / 30;
                //if(days % 30)
                    //months++;
                //cout << months << endl;

                //int weeks = days / 7;
                //if(days % 7)
                    //weeks++;
                //cout << weeks << endl;

                //cout << days << endl;
            //}
    //}
//}



//==================================================================
//test for cmpDates
//int main() {
    //int year, month, day;
    //while(cin >> year >> month >> day) {
        //int bornDate[3] = {year, month, day};
        //cin >> year >> month >> day;
        //int presentDate[3] = {year, month, day};
        //if(!isValidDate(bornDate) || !isValidDate(presentDate))
            //cout << "invalid date!" << endl;
        //else {
            //if(cmpDates(bornDate, presentDate))
                //cout << "right enddate!" << endl;
            //else 
                //cout << "wrong enddate!" << endl;
        //}
    //}
//}
//==================================================================
//test for invalidDate
//int main() {
    //int year, month, day;
    //while(cin >> year >> month >> day) {
        //int bornDate[3] = {year, month, day};
        //if(!isValidDate(bornDate))
            //cout << "invalid date!" << endl;
        //else 
            //cout << "valid date!" << endl;
    //}
//}