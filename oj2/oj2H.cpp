#include <iostream>
using namespace std;
//打印1000以内的完数
bool isC(int n)
{
    int add = 0;
    if(n==1){
        return false;
    }
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            add += i;
        }
    }
    if (add + 1 == n)
    {
        return true;
    }
    else return false;
};

int main()
{
    for (int j = 1;j<=1000;++j)
    {
        if(isC(j)){
            cout<<j<<endl;
        }
    }
}