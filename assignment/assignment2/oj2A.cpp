#include <iostream>
using namespace std;
//比大小，从小到大输出
//没什么稀奇，过于丑陋的穷举(
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (a < b)
        {
            if(a<c){
                if(b<c){
                    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
                }
                else cout<<a<<" "<<c<<" "<<b<<" "<<endl;
            }
            else cout<<c<<" "<<a<<" "<<b<<" "<<endl;
        }
        else if(b>c){
            cout<<c<<" "<<b<<" "<<a<<" "<<endl;
            }
        else if (a>c){
            cout<<b<<" "<<c<<" "<<a<<" "<<endl;
        }
        else if(c>a){
            cout<<b<<" "<<a<<" "<<c<<" "<<endl;
        }
    }
}
