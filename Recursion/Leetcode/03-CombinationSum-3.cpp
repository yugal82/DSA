// Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
    // Only numbers 1 through 9 are used.
    // Each number is used at most once.
// Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(int idx, int target, int k, vector<int> &subsequences, vector<vector<int>> &ans){
        if(idx > 10) return;
        if(k == 0){
            if(target == 0) ans.push_back(subsequences);

            return;
        }
        if(idx > target) return;

        // include current number in the 'subsequences' array
        subsequences.push_back(idx);
        solve(idx+1, target - idx, k-1, subsequences, ans);

        // do not include current number in the 'subsequences' array
        subsequences.pop_back();
        solve(idx+1, target, k, subsequences, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> subsequences;
        vector<vector<int>> ans;

        solve(1, n, k, subsequences, ans);

        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> ans = s.combinationSum3(3, 9);
    for(auto i : ans){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}