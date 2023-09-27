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
