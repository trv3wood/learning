#include <iostream>
using namespace std;

// This program prints a pyramid of characters based on user input
// The first input is a character to be printed
// The second input is the number of rows in the pyramid
// For example, if the input is 'A' and 5, the output should be:
//     A
//    AAA
//   AAAAA
//  AAAAAAA
// AAAAAAAAA
// The program should keep reading input until the end of file
int main() {
    char ch;
    int n;
    while (cin >> ch >> n) { // read input character and number of rows and pattern
        for(int j = 1 ; j<=n ;++j) { // loop through each pattern 
            for(int i = 1; i <= j; i++){ // loop through each row
                for (int x = 1; x <= n - i; x++) { // print spaces before the character
                    cout << " ";
                }
                for (int x = 1; x <= 2 * i - 1; x++) { // print the character
                    cout << ch;
                }
            cout<<endl; // move to the next line after each row is printed
            }
        }
    }
    return 0;
}