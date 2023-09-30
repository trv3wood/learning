#include <iostream>
//不通过
using namespace std;

int main() {
   float X, Y, Z;

    for (X = 0; X <= 500; X++) {
        for (Y = 0; Y <= 500; Y++) {
            for (Z = 0; Z <= 500; Z++) {
                if (X * Y * Z + Y * Z * Z == 532) {
                   cout << "X=" << X << endl << "Y=" << Y <<endl<< "Z=" << Z << endl;
               }
           }
       }
   }
    return 0;
}