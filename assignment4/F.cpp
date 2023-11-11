/*输入一个表示星期几的数，然后输出相应的英文单词。要求：使用指针数组实现
输入
一个整数，表示星期几
输出
输入对应的英文单词
样例输入 Copy
1
3
样例输出 Copy
monday
wednesday
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char *week[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
    int n;
    while(cin >> n) 
        cout << week[n - 1] << endl;
    return 0;
}