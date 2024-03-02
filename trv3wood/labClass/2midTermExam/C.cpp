//L代表火车的长度，D代表隧道的距离，t代表时间
//求过了一段时间t后，火车在隧道内的长度
//L represents the length of the train, D represents the distance of the tunnel, and t represents the time
//Find the length of the train in the tunnel after a period of time t
#include <iostream>
using namespace std; 

int main() {
    float L,D,t;
    const float v = 10.0;
    while(cin >> L >> D >> t) {
        float time2 = D / v;//time to pass the tunnel
        float time1 = L / v;//time to pass the train
        if(L <= D) {
            //if the length of the train is less than the distance of the tunnel
            if(t <= time1) {
                cout << v * t << endl;
            }
            else if(t > time2) {
                cout << (L - v * (t - time2)) << endl;
            }
            else if(t > time1 && t <= time2) {
                cout << L << endl;
            }
        }
        else {
            //if the length of the train is greater than the distance of the tunnel
            if( t < time2) {cout << v * t << endl;}
            else if(t >= time2 && t < time1) {cout << D << endl;}
            else {
                cout << D - v*(t - time1) << endl;
            }
        }
    }
}
