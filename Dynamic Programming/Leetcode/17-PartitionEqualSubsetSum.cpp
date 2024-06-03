// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(vector<int> &nums, int idx, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == nums.size()-1){
            if(nums[idx] == target) return true;
            else return false;
        }

        if(dp[idx][target] != -1) return dp[idx][target];

        // do not take the element in the subset
        bool notTake = solve(nums, idx+1, target, dp);

        // take the element in the subset
        bool take = false;
        if(target >= nums[idx]) 
            take = solve(nums, idx+1, target-nums[idx], dp);

        return dp[idx][target] = notTake || take;
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) totalSum += nums[i];

        if(totalSum % 2 != 0) return false;
        
        int target = totalSum/2;
        vector<vector<int>> dp(201, vector<int>(target+1, -1));
        return solve(nums, 0, target, dp);
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4};
    cout<<obj.canPartition(nums);
    return 0;
}