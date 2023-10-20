# oj1
 - oj1
   - [oj1A](#A)
   - [oj1B](md/#B)
   - [oj1C](docs/oj1.md/#C)
## A
*in squre*

```cpp
#include <iostream>
//给定坐标判断是否在矩形内
int main()
{
    float X, Y;
    while (std::cin >> X >> Y)
    {
        std::cout << ((X <= 2 && X >= -2 && Y <= 2 && Y >= -2) ? "true" : "false") << std::endl;
    }
}
```

## B
*找最小值*

```cpp
#include <iostream>
int main(){
    int a,b,c;
    while (std::cin>>a>>b>>c)//取最小的整数
    {
        std::cout<<(a<=b?(a<=c?a:c):(b<=c?b:c))<<std::endl;
    }
}
```
## C
*逆序打印五位数*

```cpp
#include <iostream>
int main()
{
    int number;
    while (std::cin>>number)
    {
        if(number < 10000 || number > 99999){
       std::cout<<"请输入五位整数";
        }
        else
         while (number > 0)
        {
            std::cout << (number % 10) <<"  ";
            number /= 10;
        }
        std::cout<<std::endl;
     }
}
``````