# oj2
## A
```cpp
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
``````
*A的另一种解法*

就是用vector排序咯

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
//三个数比大小另解
int main(){
    int x,y,z;
    while(std::cin>>x>>y>>z){
        std::vector<int> vec = {x,y,z};
        std::sort(vec.begin(),vec.end());
		for(int i = 0;i < 3;i++){
			std::cout<<vec[i]<<" ";
		}
		std::cout<<std::endl;
    }
}
``````
## B
```cpp
#include <iostream>
using namespace std;
// 模拟“剪刀、石头、布”游戏。
// 利用ASCII码判断
int main() {
  char a, b;
  while (cin >> a >> b) {
    int A = static_cast<int>(a);
    int B = static_cast<int>(b);
    if (A - B == 3)
      cout << "甲方胜" << endl;
    else if (A - B == 2)
      cout << "乙方胜" << endl;
    else if (A - B == 1)
      cout << "乙方胜" << endl;
    else if (A - B == -3)
      cout << "乙方胜" << endl;
    else if (A - B == -2)
      cout << "甲方胜" << endl;
    else if (A - B == -1)
      cout << "甲方胜" << endl;
    else if (A == B)
      cout << "平局" << endl;
  }
}
``````
## C
```cpp
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

string decimal2binary(int n) {
  string binary = "";
  while (n > 0) {
    binary = to_string(n % 2) + binary;
    n /= 2;
  }
  return binary;
};
int main() {
  cout << "decimal\tbinary\t\toctal\thexadecimal" << endl;
  for (int i = 1; i < 128; ++i) {
    cout << dec << i << "\t";
    cout << decimal2binary(i) << "\t\t";
    cout << oct << i << "\t";
    cout << hex << i << "\t" << endl;
  }
  for (int i = 128; i <= 256; ++i) {
    cout << dec << i << "\t";
    cout << decimal2binary(i) << "\t";
    cout << oct << i << "\t";
    cout << hex << i << "\t" << endl;
  }
}
``````
## D
```cpp
#include <iostream>
using namespace std;
// 提取整数的素数因子
bool isPrime(int n) {
  if (n <= 1) {
    return false;
  }
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
};
int main() {
  int num;
  while (cin >> num) {
    if (isPrime(num))
      cout << num << " ";
    else
      for (int i = 2; i <= num; i++) {
        while (isPrime(i) && num % i == 0) {
          cout << i << " ";
          num = num / i;
        }
      }
  }
}
``````
## E
```cpp
#include <iostream>
using namespace std;
//用迭代公式计算平方根
double squareRoot(int n,double epsilon){
    double x0=n*0.5,x1;
    if(n<0){
        throw invalid_argument("n must be positive");
    } 
    else if(n==0 || n==1){
        return n;
    }
    else
    while(abs(x1*x1-n)>=epsilon) {
        x1=(n/x0+x0)*0.5;
        x0=x1;
    }
    return x1;
};

int main(){
    int n;
    double epsilon=1e-8;
    while (cin>>n)
    {
        cout<<squareRoot(n,epsilon)<<endl;
    }
    
}
``````
## F
```cpp
#include <iostream>
using namespace std;
//用迭代公式计算平方根
double squareRoot(int n,double epsilon){
    double x0=n*0.5,x1;
    if(n<0){
        throw invalid_argument("n must be positive");
    } 
    else if(n==0 || n==1){
        return n;
    }
    else
    while(abs(x1*x1-n)>=epsilon) {
        x1=(n/x0+x0)*0.5;
        x0=x1;
    }
    return x1;
};

int main(){
    int n;
    double epsilon=1e-8;
    while (cin>>n)
    {
        cout<<squareRoot(n,epsilon)<<endl;
    }
    
}
``````
## G
```cpp
#include <iostream>
//求水仙花数
int main() {
    for(int i = 100; i <= 999; ++i) {
        int a = i / 100;
        int b = (i /10) % 10;
        int c = i % 10;
        if(i == a*a*a+b*b*b+c*c*c) {
            std::cout<<i<<std::endl;
        }
    }
}
``````
## H
```cpp
#include <iostream>
using namespace std;
// 打印1000以内的完数
bool isC(int n) {
  int add = 0;
  if (n == 1) {
    return false;
  }
  for (int i = 2; i < n; ++i) {
    if (n % i == 0) {
      add += i;
    }
  }
  if (add + 1 == n) {
    return true;
  } else
    return false;
};

int main() {
  for (int j = 1; j <= 1000; ++j) {
    if (isC(j)) {
      cout << j << endl;
    }
  }
}
``````
## I
```cpp
#include <iostream>
using namespace std;
// 打印空心方形
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; ++i) {
      cout << "* ";
    }
    cout << endl;
    for (int i = 1; i <= n - 2; ++i) {
      cout << "*";
      for (int j = 1; j <= 2 * n - 3; ++j) {
        cout << " ";
      }
      cout << "*" << endl;
    }
    for (int i = 1; i <= n; ++i) {
      cout << "* ";
    }
  }
}
``````
## J
```cpp
#include <iostream>
using namespace std;

//J终于过了，是我没理解题意，不是X*Y*Z，而是每位数字啊啊啊
//已知XYZ+YZZ=532，其中X、Y和Z为数字，编写程序求出X、Y和Z的值
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
``````
## K
```cpp
#include <iostream>
#include <string>

using namespace std;
//K终于过了，oj跟字符串有什么仇

string encrypt(int plainText) {
    
    string encrypted = "";
    
    for(int i = 0; i < 6; i++) {
        int num = plainText % 10;
        int encryptedText = (num + 7) % 10;
        encrypted = encrypted + to_string(encryptedText);
        plainText /= 10;
    }
    
    return encrypted;
}

void decrypt(string encrypted) {
    
    cout << "解密：";
    
    for(int i = 5; i >= 0; --i) {
        int decryptedText = (encrypted[i]-'0'+3) % 10;
        cout<< decryptedText ;
    }
    
    cout << endl;
}

int main() {
    int plainText;
    
    while(cin>>plainText) {
        
        if(plainText>=100000 && plainText<=999999){
        
        string encrypted = encrypt(plainText);
        
        cout <<"加密：";

        for(int i = 0; i <6; ++i){
            cout<< encrypted[i] - '0' ;
        }
        
        cout<<endl;

        decrypt(encrypted);
        }
        
        else{
        
        cout<<"输入错误，退出程序。"<<endl;
        
        }
    }
}
``````