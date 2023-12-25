// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(int n, int idx, int k, int count, vector<int> &subsequences, vector<vector<int>> &ans){
        if(count < 0) return;
        if(idx == n){
            if(subsequences.size() == k) ans.push_back(subsequences);
            return;
        }

        // put the current element in the subsequnce 
        subsequences.push_back(idx+1);
        count -= 1;
        solve(n, idx+1, k, count, subsequences, ans);

        // do not take the current element in the subsequnces
        subsequences.pop_back();
        count += 1;
        solve(n, idx+1, k, count, subsequences, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> subsequences;
        vector<vector<int>> ans;

        solve(n, 0, k, k, subsequences, ans);

        return ans;
    }
};

int main(){
    int n = 4;
    int k = 2;
    Solution obj;
    vector<vector<int>> ans = obj.combine(n, k);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}