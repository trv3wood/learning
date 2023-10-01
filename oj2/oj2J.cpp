#include <iostream>
using namespace std;

//J终于过了，是我没理解题意，不是X*Y*Z，而是每位数字啊啊啊
int main()
{
    for (int x = 1; x < 6; x++)
    {
        for (int y = 1; y < 6; y++)
        {
            for (int z = 0; z < 10; z++)
            {
                if (532 == 100 * x + 110 * y + 12*z)
                {
                    cout << "x=" << x <<endl<< "y=" << y <<endl<< "z=" << z << endl;
                }
            }
        }
    }
}