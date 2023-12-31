/*在物理学中基本粒子可分为玻色子与费米子两大类。
假设有n（1<=n<=9）个同种粒子，
初始排布表示为字符串123…n，
对于玻色子，交换不同位置的粒子后量子态不变，
即对于123…n的任意一个全排列量子态不变；对于费米子，
交换一次任意两个粒子都会导致量子态多出一个负号，再交换一次才会回到原来的量子态（负负得正），
即对于123…n的奇排列，量子态多出一个负号，对于偶排列，则回到原来的量子态。用字符’+’表示原来的量子态，
用’-‘表示多出一个负号的量子态，对于给定的n和123…n的一个排列，
以及从初始排布变换到这个排列后的量子态（用’+’或’-‘表示），请判断所操作的粒子是玻色子还是费米子。
输入
多组输入，每行一个123…n的全排列字符串（1<=n<=9），以及一个表示该排列量子态的字符（’+’或’-‘）
输出
如果判断为玻色子，输出’B’，如果判断为费米子，输出’F’，如果不能从输入确定（交换两次后，不管是玻色子还是费米子都是’+’），输出’P’
样例输入 Copy
1 +  
21 + 
21 - 
12 + 
12345 + 
31254 + 
45213 - 
7654321 + 
987654321 + 
样例输出 Copy
P
B
F
P
P
B
F
B
P
提示
字符串123…n中字符的一个奇排列总能通过交换奇数次其中的字符回到原来的字符串，例如奇排列321通过交换一次3和1便回到123，偶排列则需要偶数次。*/

#include <bits/stdc++.h>
using namespace std;

char determineParticleType(const std::string& permutation, char quantumState) {
    int numSwaps = 0;
    int n = permutation.length();

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (permutation[i] > permutation[j]) {
                numSwaps++;
            }
        }
    }

    if(numSwaps % 2 == 0) {
        return 'P';
    } else {
        if(quantumState == '+')
            return 'B';
        else
            return 'F';
    }
    return 'P';
}

int main() {
    string permutation;
    char quantumState;

    while (cin >> permutation >> quantumState) {
        char particleType = determineParticleType(permutation, quantumState);
        cout << particleType << endl;
    }

    return 0;
}
