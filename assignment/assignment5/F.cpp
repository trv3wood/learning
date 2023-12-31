/*我们给出一种最简单的加密方法，给定一个字符串，
把其中从a-y，A-Y的每个字符用其ASCII码反转得到的一个新的整数作为密文。
为确保密文满足整数的常见形式（即：除0外，最高位数字不应该为0.），
并能正确解密，如果字符的ASCII码反转得到的新的整数最高位为0，则密文为原始ASCII码。
例如：
字符A的ASCII码为97，密文为79；
字符N的ASCII码为110，密文为110；
输入
多组输入。每次输入一行，包含一个字符串，长度小于80个字符。
输出
对应多组输出。每次输出一行字符串加密后的密文，整数方式输出，每个密文间用单个空格分隔。
样例输入 Copy
AbCdEf
Fnx
样例输出 Copy
56 89 76 100 96 201
70 110 120
提示
多组测试用例，每组输出完成后注意换行*/
#include <bits/stdc++.h>
using namespace std;

void encrypt(string plainTexts) {
    vector<int> encryptedTexts;
    for(char plainText : plainTexts) {
        string ascii = to_string(toascii(plainText));

        if(ascii.back() == '0')
            encryptedTexts.emplace_back(stoi(ascii));
        else {
            reverse(ascii.begin(), ascii.end());
            encryptedTexts.emplace_back(stoi(ascii));
        }
    }
    for(int num : encryptedTexts)
        cout << num << " ";
}

int main() {
    string plainTexts;
    while(getline(cin, plainTexts)) {
        encrypt(plainTexts);
        cout << endl;
    }
}