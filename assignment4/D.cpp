//回文数
bool isPalindrome(int x) {
    if(x < 0)
        return false;
    int y = 0;//y是x的逆序数
    int tmp = x;
    while(tmp){
        y = y * 10 + tmp % 10;
        tmp /= 10;
    }
    return x == y;
}
//反转字符串hh(to do)