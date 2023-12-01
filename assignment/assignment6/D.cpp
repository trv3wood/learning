/*设计函数，不使用辅助数组，实现两个 int 型或 double 型数组中数据的快速交换。
Input
一个整数，代表四个数组的长度，两个整型数组，两个double型数组
Output
交换后的四个数组（每一个数组结束需要换行）
Sample Input Copy
5
1 2 3 4 5
6 9 8 7 10
1.1 2.2 3.3 4.4 5.5
6.6 7.7 8.8 9.9 10.1
3
5 6 9
12 23 56
2.6 5.9 9.5
6.6 55.5 66.6
Sample Output Copy
6 9 8 7 10
1 2 3 4 5
6.6 7.7 8.8 9.9 10.1
1.1 2.2 3.3 4.4 5.5
12 23 56
5 6 9
6.6 55.5 66.6
2.6 5.9 9.5*/
#include <bits/stdc++.h>
using namespace std;

//交换两个数组的内容
void exchange(vector<int>& v1, vector<int>& v2) {
    for(int i = 0; i < v1.size(); i++) {
        swap(v1[i], v2[i]);//swap函数交换两个变量的值
    }
}

//重载exchange 函数，交换两个float数组的内容
void exchange(vector<float>& v1, vector<float>& v2) {
    for(int i = 0; i < v1.size(); i++) {
        swap(v1[i], v2[i]);
    }
}
//自动输入数据到vector
void autoInput(vector<int>& v) {
    for(auto it = v.begin(); it != v.end(); it++) {
        cin >> *it;
    }
    return;
}
//自动输出vector的内容
void autoPrint(vector<int>& v) {
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
    return;
}
//重载autoInput函数，自动输入float型数据到vector
void autoInput(vector<float>& v) {
    for(auto it = v.begin(); it != v.end(); it++) {
        cin >> *it;
    }
    return;
}
//重载autoPrint函数，自动输出float型vector的内容
void autoPrint(vector<float>& v) {
    for(auto it = v.begin(); it != v.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
    return;
}

int main() {
    int size;
    
    while (cin >> size) {
        vector<int> intV1(size);
        vector<int> intV2(size);
        vector<float> fV1(size);
        vector<float> fV2(size);
        autoInput(intV1);
        autoInput(intV2);
        exchange(intV1, intV2);

        autoInput(fV1);
        autoInput(fV2);
        exchange(fV1, fV2);

        autoPrint(intV1);
        autoPrint(intV2);
        autoPrint(fV1);
        autoPrint(fV2);
        
    }
}
