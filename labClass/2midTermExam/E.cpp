//素数是指大于1且除了1和它本身以外不再有其他因数的自然数。
//回文数是指正读和反读一样的自然数。
//例如，121，1221，1223221等都是回文数。输入任意两个整数m和n, 
//输出m和n之间的素回文数，如果没有，则输出“无”。
//prime number is a natural number greater than 1 and has no other factors except 1 and itself.
//palindrome is a natural number that reads the same forward and backward.
//For example, 121, 1221, 1223221, etc. are all palindromes. Enter any two integers m and n,
//output the prime palindrome between m and n, if not, output "none".
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPalindrome(unsigned int x) {
    //convert x to string
    std::string str = std::to_string(x);
    //check if the string is a palindrome
    for(int i = 0; i < str.length() -i -1; ++i){

        //j is the symmetric position of i
        int j = str.length() - i -1;

        if(str[i] != str[j])
            return false; 
    }
        return true;
}
bool isPrime(unsigned int x) {
    if(x == 1)
        return false;
    for(int i = 2; i < x; ++i)
        if(x % i == 0)
            return false;
    return true;
}

int main() {
    int x,n;
    while(cin >> x >> n) {
        vector<int> res;
        for(int i = min(x,n); i <= max(x,n); ++i) {
            if(isPalindrome(i) && isPrime(i))
                res.push_back(i);
            if(res.empty())
                cout << "无" << endl;
            else {
                for(int i = 0; i < res.size(); ++i)
                    cout << res[i] << " ";
                cout << endl;
            }
        }
    }
}