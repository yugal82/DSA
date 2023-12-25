// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).        The solution set must not contain duplicate subsets. Return the solution in any order.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(vector<int> &nums, int idx, vector<int> &subSequences, set<vector<int>> &s){
        if(idx == nums.size()){
            s.insert(subSequences);
            return;
        }

        // take the particular element in the subsequence
        subSequences.push_back(nums[idx]);
        solve(nums, idx+1, subSequences, s);

        // do not take the particular element in the subsequence
        subSequences.pop_back();
        solve(nums, idx+1, subSequences, s);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subSequences;
        vector<vector<int>> ans;
        set<vector<int>> s;
        solve(nums, 0, subSequences, s);

        for(auto &it:s)
            ans.push_back(it);

        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,2};
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    for(auto &it:ans)
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;

    return 0;
}