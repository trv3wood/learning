#include <iostream>
using namespace std;

int main()
{
	int x;
	while (cin >> x)
	{
		if (x >= 10000 && x <= 99999)
		{
			cout << x % 10 << "  " << x / 10 % 10 << "  " << x / 100 % 10 << "  " << x / 1000 % 10 << "  " << x / 10000 % 10 << endl;
		}
		else
			cout << "输入不是五位正整数。" << endl;
	}
}
