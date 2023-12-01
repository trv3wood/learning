//输入一个正整数 n，输出一个沙漏形，
//这个沙漏形有 2n+1 行，第一行有 2n+1 个字母，
//其中前 n+1 个字符是从 A 开始依次递增的，
//而后 n 个字符是由第 n+1 个字符开始依次递减的。
//之后的 n行每行会少头尾两个字母。
//再之后的 n 行则正好是前 n 行反过来输出的结果。
//注意末尾不要有多余的输出。
//例如 n=2 时，输出如下：
//ABCBA  
  //BCB  
   //C 
  //BCB 
 //ABCBA

//input a positive integer n, output a sandglass shape,
//the sandglass shape has 2n+1 lines, the first line has 2n+1 letters,
//the first n+1 characters are incremented from A in turn,
//and the next n characters are decremented from the n+1 character in turn.
//The next n lines will have two fewer letters at the beginning and end.
//The next n lines are exactly the result of the first n lines reversed.
//Be careful not to have extra output at the end.
//For example, when n=2, the output is as follows:
//ABCBA  
  //BCB  
   //C 
  //BCB 
 //ABCBA
#include <bits/stdc++.h>
using namespace std;

void getStr(int n) {
    string str = "";
    vector<string> res;//store the result

    //construct the first line
    for(int i = 0; i <= n; i++){
        str += 'A' + i;
    }

    //remove the last letter, reverse the string, and add it to the end
    string tmp = str;
    tmp.pop_back();
    reverse(tmp.begin(), tmp.end());
    str += tmp;
    res.push_back(str);//store the result of first line

    //output the first line
    cout << str << endl;

    //remove the first and last letter, replace them with spaces
    for(int i = 0; i < n; i++) {
        str.replace(i, 1, " ");
        str.replace(str.size() - 1 - i, 1, " ");
        res.push_back(str);//store the result of each line
        cout << str << endl;
    }

    //reverse output
    for(int i = res.size() - 2; i >= 0; i--) {
        cout << res[i] << endl;
    }
}
int main() {
    int n;
    while(cin >> n) {
        getStr(n);
    }
}