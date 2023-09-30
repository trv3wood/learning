#include <iostream>
using namespace std;

void decimal_to_binary(int decimal)
{
    int binary[9], i = 0;
    for (; decimal > 0; ++i)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
    }
    for (i--; i >= 0; i--)
    {
        cout << binary[i];
    }
};

int main()
{
    cout << "Decimal\tbinary\t\toctal\thexadecimal" << endl;

    for (int i = 1; i < 128; ++i)
    {
        cout << dec << i << "\t";
        decimal_to_binary(i);
        cout << "\t\t";
        cout << oct << i << "\t";
        cout << hex << i << "\t" << endl;
    }
    for (int i = 128; i <= 256; ++i)
    {
        cout << dec << i << "\t";
        decimal_to_binary(i);
        cout << "\t";
        cout << oct << i << "\t";
        cout << hex << i << "\t" << endl;
    }
}