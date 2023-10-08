#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 1672. Richest Customer Wealth(https://leetcode.com/problems/richest-customer-wealth/)
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> wealthList;
        int sum;
        for(int i =0;i<accounts.size();i++){
            for(int j = 0;j < accounts[i].size();++j){
                sum += accounts[i][j];
            }
            wealthList.push_back(sum);
            sum = 0;
        }
        auto max = max_element(wealthList.begin(),wealthList.end());
        int wealthest = *max;
        return wealthest;
    }
};
int main(){
    vector<vector<int>> accounts = {{1,2,3},{3,2,1}};
    Solution sol;
    int result = sol.maximumWealth(accounts);
    cout << result;
}