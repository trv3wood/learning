//找出从4到N（N>=4），每隔2递减数列中所有素数（N,N-2,N-4……),
//素数从小到大排列。
//输出4～N的所有隔项素数，
//用空格隔开，如果没有，则输出None,
//每组数据分行输出。
//find all prime numbers in the decreasing sequence from 4 to N (N>=4) with a gap of 2 (N,N-2,N-4...),
//and sort the prime numbers from small to large.
//output all the prime numbers from 4 to N with a gap,
//separated by spaces, if not, output None,
//and output each group of data in a line.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPrime(int x) {
    if(x == 1)
        return false;
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0)
            return false;
    return true;
}
void getPrime(int n) {
    vector<int> res;

    //if n is even, the result of decreasing 2 is not a prime number obviously
    if(n % 2 == 0) {
        cout << "None" << endl;
        return;
    }

    //find all prime numbers in the decreasing sequence from 4 to N (N>=4) with a gap of 2 (N,N-2,N-4...),
    for(int i = n; i >= 4; i -= 2) {
        if(isPrime(i))
            res.emplace_back(i);
    }

    //if there is no prime number, output None
    if(res.empty())
        cout << "None" << endl;
        
    //output all the prime numbers from 4 to N with a gap,
    else {
        for(int i = res.size() - 1; i >= 0; --i) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
int main() {
    int n;
    while(cin >> n)
        getPrime(n);
}