//输入产生 10 个互不相同的两位整数存放到一维数组中，并输出其中的素数
#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    string s;
    while(getline(cin, s)) {
        vector<int> v;
        stringstream ss(s);
        while(ss >> num) {
            v.push_back(num);
        }
       for(int i = 0; i < v.size(); i++) {
           int flag = 0;
           for(int j = 2; j < v[i]; j++) {
               if(v[i] % j == 0) {
                   flag = 1;
                   break;
               }
           }
           if(flag == 0) {
               cout << v[i] << " ";
           }
        }
        cout << endl;
    }
    return 0;
}