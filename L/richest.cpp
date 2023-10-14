#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//http://leetcode 1672
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
    vector<int>onesWealth;
    int add;
    for(int i = 0;i<accounts.size();++i){
        for(int j=0;j<accounts[0].size();j++){
            add+=accounts[i][j];
        }
        onesWealth.emplace_back(add);
        add=0;
        }
    //sort(onesWealth.begin(),onesWealth.end());
    //return onesWealth[onesWealth.size()-1];
    vector<int>::iterator Max = max_element(onesWealth.begin(),onesWealth.end());
    return *Max;
  }
};
int main(){
  vector<vector<int>> accounts = {{1,2,3},{3,2,1}};
  Solution s;
  cout<<s.maximumWealth(accounts);
}