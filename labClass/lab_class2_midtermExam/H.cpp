//将一个三位数x交换个位和百位后得到新数y，设y-x=K,
//问当给定一个K值时，有多少满足这个条件的三位数，
//将它们全部输出，如果没有，输出None,以空格隔开，每组数据换行。
//swap the units and hundreds of a three-digit number x to get a new number y, and let y-x=K,
//ask how many three-digit numbers satisfy this condition when given a K value,
//and output all of them, if not, output None, separated by spaces, and output each group of data in a line.
#include <iostream>
using namespace std;

int main() {
    int K;
    while(cin >> K) {
        int count = 0;
        for(int i = 100; i < 1000; ++i) {
            int x = i;
            int y = x / 100 + (x % 10) * 100 + 
            (x / 10 % 10) * 10;
            if(y - x == K) {
                ++count;
                cout << x << " ";
            }
        }
        if(count == 0)
            cout << "None" << endl;
        else
            cout << endl;
    }
}