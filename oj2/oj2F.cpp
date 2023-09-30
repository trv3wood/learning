#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double pi = 3.1415926;
    double i = 0;

    for (; i <= 180; i += 10){
        double x = i / 180 * pi;
        cout << sin(x) << " " << cos(x) << " " << tan(x) << endl;
    }
}
