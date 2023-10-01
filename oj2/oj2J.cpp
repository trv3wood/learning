#include <iostream>

using namespace std;
//没过
int main()
{
    for (int Y = 1; Y < 150; Y++)
    {
        for (int Z = 1; Z < 150; Z++)
        {
            int X = 5;
            int sum = X * Y * Z + Y * Z * Z;
            while (sum > 532)
            {
                X--;
                sum = X * Y * Z + Y * Z * Z;
            }
            while (sum < 532)
            {
                X++;
                sum = X * Y * Z + Y * Z * Z;
            }
            if (sum == 532)
            {
            cout << "X=" << X<<endl << "Y=" << Y <<endl<< "Z=" << Z << endl;
            }
        }
    }
    return 0;
}