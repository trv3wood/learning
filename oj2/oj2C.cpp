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