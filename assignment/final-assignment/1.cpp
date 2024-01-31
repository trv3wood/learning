// @author: sour
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
void remove(string &x)//去掉逗号
{
	int len = x.length();
	for (int i = 0; i < len; i++) {
		if (x[i] == ',') {
			x.erase(i, 1);
			i--;
			len--;
		}
	}
}
int* jia(int*x1,int m1, int* y1,int n1,int&i) //加的函数，返回加完之后的那个数组
{
	int* m = new int[10000];
	while (m1 != 0 && n1 != 0) {
		m[i++] = x1[m1-1] + y1[n1-1];
		m1 --;
		n1 --;
	}
	while (m1 != 0) {
		m[i++] = x1[m1-1];
		m1 --;
	}
	while (n1!= 0) {
		m[i++] = y1[n1-1];
		n1--;
	}
	for (int j = 0; j <i-1; j++) {
		if (m[j] >= 10) {
			m[j] -= 10;
			m[j + 1] += 1;
		}
	}
	if (m[i - 1] >= 10) {
		m[i - 1] -= 10;
		m[i] = 1;
		i++;
	}
	return m;
}
int* jian(int* x2, int m2, int* y2,int n2, int&i) //减的函数，返回剪完之后的那个数组
{
	int* n = new int[10000];
	while (m2 != 0 && n2 != 0) {
		n[i++] = x2[m2-1] - y2[n2-1];
		m2 --;
		n2 --;
	}
	while (m2 != 0) {
		n[i++] = x2[m2-1];
		m2 --;
	}
	while (n2 != 0) {
		n[i++] = y2[n2-1];
		n2--;
	}
	for (int j = 0; j < i; j++) {
		if (n[j] < 0) {
			n[j] += 10;
			n[j + 1]--;
		}
	}
	return n;
}
int main() {
	int n;//代表要进行n组运算
	char t;//加还是减
	while(cin >> n){
	int num = 0;
	string* outcome = new string[n];
	for (num = 0; num < n; num++)
	{
		int a[10000], b[10000];
		int* c = new int[10000];		
		string aa, bb;
		int len = 0;
		cin >> t;
		cin >> aa >> bb;
		remove(aa);remove(bb);
		if (t == '+' && aa[0] != '-' && bb[0] != '-') //全是正数加
		{
			for (int i = 0; i < aa.length(); i++)
				a[i] = aa[i] - '0';
			for (int i = 0; i < bb.length(); i++)
				b[i] = bb[i] - '0';
			c = jia(a, aa.length(), b, bb.length(), len);
		}
		else if (t == '+' && aa[0] == '-' && bb[0] == '-') //全是负数加
		{
			for (int i = 1; i < aa.length(); i++)
				a[i - 1] = aa[i] - '0';
			for (int i = 1; i < bb.length(); i++)
				b[i - 1] = bb[i] - '0';
			c = jia(a, aa.length() - 1, b, bb.length() - 1, len);
			cout << "-";
		}
		else if (t == '+' && aa[0] != '-' && bb[0] == '-')//加了个负数
		{
			for (int i = 0; i < aa.length(); i++)
				a[i] = aa[i] - '0';
			for (int i = 1; i < bb.length(); i++)
				b[i - 1] = bb[i] - '0';
			if (aa.length() > bb.length() - 1 || aa.length() == bb.length() - 1 && a[0] > b[0])//如果a减的够b
				c = jian(a, aa.length(), b, bb.length() - 1, len);
			else//减不够就调换
			{
				c = jian(b, bb.length() - 1, a, aa.length(), len);
				cout << "-";
			}
		}
		else if (t == '+' && bb[0] != '-' && aa[0] == '-') //负数加正数
		{
			for (int i = 0; i < bb.length(); i++)
				b[i] = bb[i] - '0';
			for (int i = 1; i < aa.length(); i++)
				a[i - 1] = aa[i] - '0';
			if (aa.length() - 1 < bb.length() || aa.length() - 1 == bb.length() && a[0] < b[0])//如果b减的够a
				c = jian(b, bb.length(), a, aa.length() - 1, len);
			else//减不够就调换
			{
				c = jian(a, aa.length() - 1, b, bb.length(), len);
				cout << "-";
			}
		}
		else if (t == '-' && aa[0] != '-' && bb[0] == '-')//减负数
		{
			for (int i = 0; i < aa.length(); i++)
				a[i] = aa[i] - '0';
			for (int i = 1; i < bb.length(); i++)
				b[i - 1] = bb[i] - '0';
			c = jia(a, aa.length(), b, bb.length() - 1, len);
		}
		else if (t == '-' && aa[0] != '-' && bb[0] != '-')//正常减法
		{
			for (int i = 0; i < aa.length(); i++)
				a[i] = aa[i] - '0';
			for (int i = 0; i < bb.length(); i++)
				b[i] = bb[i] - '0';
			if (aa.length() > bb.length() || aa.length() == bb.length() && a[0] > b[0])//如果a减的够b
				c = jian(a, aa.length(), b, bb.length(), len);
			else//减不够就调换
			{
				c = jian(b, bb.length(), a, aa.length(), len);
				cout << "-";
			}
		}

		else if (t == '-' && aa[0] == '-' && bb[0] == '-')//负数减负数
		{
			for (int i = 1; i < aa.length(); i++)
				a[i - 1] = aa[i] - '0';
			for (int i = 1; i < bb.length(); i++)
				b[i - 1] = bb[i] - '0';
			if (aa.length() < bb.length() - 1 || aa.length() == bb.length() - 1 && a[0] < b[0])
				c = jian(b, bb.length() - 1, a, aa.length() - 1, len);
			else
			{
				c = jian(a, aa.length() - 1, b, bb.length() - 1, len);
				cout << "-";
			}
		}
		else if (t == '-' && aa[0] == '-' && bb[0] != '-')//负数减正数
		{

			for (int i = 1; i < aa.length(); i++)
				a[i - 1] = aa[i] - '0';
			for (int i = 0; i < bb.length(); i++)
				b[i] = bb[i] - '0';
			c = jia(b, bb.length(), a, aa.length() - 1, len);
			cout << "-";
		}
		int m = len;
		string out="";
		while (c[m - 1] < 1 && m>0) {
			m--;
		}
		for (int i = 0; i <= m - 1; i++)
		{
			out += to_string(c[i]);
			if ((i + 1) % 3 == 0&&i!=m-1)
				out += ',';
		}
		outcome[num] = out;
	}
	for (int amo = 0; amo < n; amo++) {
		reverse(outcome[amo].begin(),outcome[amo].end());//逆序
		cout << outcome[amo];
		cout << endl;
	}
}
}