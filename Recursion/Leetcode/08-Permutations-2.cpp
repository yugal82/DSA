// Question - Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(vector<int> &nums, vector<int> &permutations, int freq[], vector<vector<int>> &ans){
        // base condition
        if(permutations.size() == nums.size()){
            ans.push_back(permutations);
            return;
        }
        int lastRemoved = 99;
        for(int i = 0; i < nums.size(); i++){
            if(!freq[i] && nums[i] != lastRemoved){
                permutations.push_back(nums[i]);
                freq[i] = 1;
                solve(nums, permutations, freq, ans);
                lastRemoved = permutations.back();
                permutations.pop_back();
                freq[i] = 0;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        vector<int> permutations;
        int freq[nums.size()];
        for(int i = 0; i < nums.size(); i++) freq[i] = 0;
        vector<vector<int>> ans;

        solve(nums, permutations, freq, ans);

        // for(auto &it:s) ans.push_back(it);

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,2};
    vector<vector<int>> ans = s.permuteUnique(nums);
    for(auto &it:ans) cout << it[0] << " " << it[1] << " " << it[2] << endl;

    // Output: [[1,1,2], [1,2,1], [2,1,1]]
    return 0;
}