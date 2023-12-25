// Given an integer array nums of unique elements, return all possible subsets (the power set).              The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(vector<int> &nums, int idx, vector<int> &subSequences, vector<vector<int>> &ans){
        if(idx == nums.size()){
            ans.push_back(subSequences);
            return;
        }

        // take the particular element in the subsequence
        subSequences.push_back(nums[idx]);
        solve(nums, idx+1, subSequences, ans);

        // do not take the particular element in the subsequence
        subSequences.pop_back();
        solve(nums, idx+1, subSequences, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subSequences;
        vector<vector<int>> ans;

        solve(nums, 0, subSequences, ans);

        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = obj.subsets(nums);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}