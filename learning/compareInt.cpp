#include <iostream>
int main()
{
    float X, Y;
    while (std::cin >> X >> Y)
    {
        std::cout << ((X <= 2 && X >= -2 && Y <= 2 && Y >= -2) ? "true" : "false") << std::endl;
    }
}
