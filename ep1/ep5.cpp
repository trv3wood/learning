#include <iostream>
using namespace std;
//过了！！！！！  
int main() {
    char ch;
    int n;
    while (cin >> ch >> n) {
        for(int j = 1 ; j<=n ;++j){
            for(int i = 1; i<=j;i++){
                for (int x = 1; x <= n - i; x++) {
                    cout << " ";
                }
                for (int x = 1; x <= 2 * i - 1; x++) {
                    cout << ch;
                }
            cout<<endl;
            }
        }
    }
    return 0;
}