// Question - Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    //  TC - O(n!) * O(n)
    void solve(vector<int> &nums, vector<int> &permutations, int isTaken[], vector<vector<int>> &ans){
        // base condition
        if(permutations.size() == nums.size()){
            ans.push_back(permutations);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(!isTaken[i]){
                permutations.push_back(nums[i]);
                isTaken[i] = 1;
                solve(nums, permutations, isTaken, ans);
                isTaken[i] = 0;
                permutations.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int isTaken[nums.size()];
        for(int i = 0; i < nums.size(); i++) isTaken[i] = 0;
        vector<int> permutations;
        vector<vector<int>> ans;

        solve(nums, permutations, isTaken, ans);

        return ans;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    Solution obj;
    vector<vector<int>> ans = obj.permute(nums);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
        cout << endl;
    }

    // Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    return 0;
}