#include <iostream>
#include <vector>
#include <algorithm>

void _sort(float a,float b) {
    if(a>b){std::cout << a << " " << b <<std::endl;}
    else {std::cout << b << " " << a << std::endl;}
}

void _sort(float c,float d,float e) {
    std::vector<float> nums = {c, d, e};
    std::sort(nums.begin(),nums.end(),[](float a,float b){return a>b;});
    for(float i:nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    float a, b, c, d, e;
    while(std::cin >> a >> b >> c >> d >> e) {
        _sort(a,b);
        _sort(c,d,e);
    }
    return 0;
}