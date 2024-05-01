// Given an array nums & integer target, check if there exists a subset in nums with sum equal to target.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool f(int idx, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(idx == 0) return (nums[0] == target);

        if(dp[idx][target] != -1) return dp[idx][target];
        bool notTake = f(idx-1, target, nums, dp);
        bool take = false;
        if(nums[idx] <= target) take = f(idx-1, target - nums[idx], nums, dp);

        return dp[idx][target] = take | notTake;
    }

    bool subsetSumToK(vector<int> &nums, int target){
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(target+1, -1));
        // return f(n-1, target, nums, dp);
        
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        dp[0][nums[0]] = true;

        for(int idx = 1; idx < n; idx++){
            for(int j = 1; j <= target; j++){
                bool notTake = dp[idx-1][j];
                bool take = false;
                if(nums[idx] <= j) take = dp[idx-1][j - nums[idx]];

                dp[idx][j] = take | notTake;
            }
        }

        return dp[n-1][target];
    }

};

int main(){
    Solution obj;
    vector<int> nums = {1,2,3,4};
    cout<<obj.subsetSumToK(nums, 5);
    return 0;
}