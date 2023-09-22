#include <iostream>
class Solution
{
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime)
    {
        return (arrivalTime + delayedTime)%24;
    }
};
int main()
{   Solution solution;
    int a,b,c;
    std::cout << "请输入正点到站的时间：";
    std::cin >> a;
    std::cout << "请输入延误时长：";
    std::cin >> b;
    c=solution.findDelayedArrivalTime(a, b);
    std::cout<< "实际到站时间为："<<c<<std::endl;
}