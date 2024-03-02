#include <iostream>
#include <algorithm>
#include <vector>
//三个数比大小另解
int main(){
    int x,y,z;
    while(std::cin>>x>>y>>z){
        std::vector<int> vec = {x,y,z};
        std::sort(vec.begin(),vec.end());
		for(int i = 0;i < 3;i++){
			std::cout<<vec[i]<<" ";
		}
		std::cout<<std::endl;
    }
}
