#include <iostream>
using namespace std;

int main() {
/*
//    2. 设变量定义 int x =10, y, z; 执行语句 y = z = x --; y = x = = z; 后变量 y 的值是 

    int x = 10;
    int y, z;
    // y = z = x--; (which is equal to the following line:)
    y = z = x; x--;


    // y = x == z;
    // to make it clear:
    y = (x == z);

    cout << "value of y: " << y << "\n";
*/

/* 
    //3. 下面 for 语句执行时循环次数为()

     //这个循环之所以会执行三次，是因为循环条件 i = j; 中的赋值操作符 = 返回被赋的值，也就是 j 的值。
    int i, j;
    for (i = 0, j = 3; i = j;) {
        std::cout << i <<" " << j << std::endl;
        i++;
        j--;
    }
*/

/*
    //6. 已知 int i = 1 ; int *Ptr1 , *Ptr2 ;下面哪条语句不合法（ C ）。
// (A)Ptr1 = &i;
// (B) Ptr1 = Ptr2;
// (C) Ptr1 = 0x1234;
// (D) Ptr1 = NULL;

    int i = 1;
    int *Ptr1, Ptr2;
    Ptr1 = 0x1234;//Incompatible integer to pointer conversion assigning to 'int *' from 'int' (clang typecheck_convert_int_pointer)
 // 该错误信息是由Clang编译器的类型检查器（type checker）生成的，它表示你在进行不兼容的整数到指针的转换。具体而言，你试图将整数值分配给指针类型的变量，这是不允许的。
 // to fix it : Ptr1 = (int*)0x1234;
*/
/*    
 // 7. 已知 char* s1= "123", *s2="34";cout<<strcmp(s1,s2);的输出结果为（ D）。
// (A)
// true
// (B) false
// (C) 1
// (D) -1
// 根据C++98的规定，strcmp 的返回值可能为负、零或正，分别表示第一个字符串小于、等于或大于第二个字符串。
// 在这个特定的例子中，"123" 比 "34" 小，因此 std::strcmp(s1, s2) 的返回值将是负数。你的代码会输出这个负数值。
    const char* s1= "123", *s2="34";cout<<strcmp(s1,s2);
*/
/*
  unsigned short a=65535;   
  short b;
  b=a;
  cout<<b;
  //程序的逻辑是将一个无符号短整型变量 a 赋值给有符号短整型变量 b。由于 a 的值为 65535，而有符号短整型的范围是 -32768 到 32767（根据常见的二补数表示法），因此 a 的值在有符号短整型中会发生溢出。在您的编译环境中，似乎采用的是一种处理溢出情况的方式，即将溢出的值映射为有符号整数类型的最小值。因此，当将 a 的值（65535）赋给有符号短整型变量 b 时，b 的值为 -1（有符号短整型的最小值）。
 */


    return 0;
}

