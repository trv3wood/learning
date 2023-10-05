#include <iostream>
#include <string>
//判断回文数
class Solution {
public:
    bool isPalindrome(unsigned int x) {
        std::string str = std::to_string(x);
        //或使用int x,判断x<0直接false，可以解决x==-10的情况
        for(int i = 0; i < str.length() -i -1; ++i){
            int j = str.length() - i -1;
            if(str[i] != str[j])
                return false; 
        }
        return true;
    }
};

int main(){
    int x;
    std::cin>>x;
    Solution sol;
    std::cout<<sol.isPalindrome(x);
}