// Q] Given an integer array nums, return the length of the longest strictly increasing subsequence

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, int prevIdx, vector<int> &nums){
        if(idx == nums.size()) return 0;

        // not take
        int len = 0 + recursion(idx+1, prevIdx, nums);
        // take
        if(prevIdx == -1 || nums[idx] > nums[prevIdx]){
            len = max(len, 1 + recursion(idx+1, idx, nums));
        }
        return len;
    }

        int memoization(int idx, int prevIdx, vector<int> &nums, vector<vector<int>> &dp){
        if(idx == nums.size()) return 0;

        if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx+1];

        // not take
        int len = 0 + memoization(idx+1, prevIdx, nums, dp);
        // take
        if(prevIdx == -1 || nums[idx] > nums[prevIdx])
            len = max(len, 1 + memoization(idx+1, idx, nums, dp));
        
        return dp[idx][prevIdx+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        // return recursion(0, -1, nums);
        // vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1, -1));
        // return memoization(0, -1, nums, dp);

        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int prevIdx = 0; prevIdx < i; prevIdx++){
                if(nums[prevIdx] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[prevIdx]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<obj.lengthOfLIS(nums);
    return 0;
}