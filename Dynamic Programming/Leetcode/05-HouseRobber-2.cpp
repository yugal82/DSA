// Q] You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    int solve(vector<int> &nums, int startIdx, int n, vector<int> &dp){
        if(n == startIdx) return nums[n];
        if(n < startIdx) return 0;

        // check if subproblem has already been solved previously. If yes, then directly return the computed value
        if(dp[n] != -1) return dp[n];
        else{
            int robHouse = nums[n] + solve(nums, startIdx, n-2, dp);
            int notRobHouse = 0 + solve(nums, startIdx, n-1, dp);

            return dp[n] = max(robHouse, notRobHouse); 
        }
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[n-1];
        vector<int> dp1(n, -1);
        vector<int> dp2(n+1, -1);
        int ans1 = solve(nums, 0, n-2, dp1);
        int ans2 = solve(nums, 1, n-1, dp2);
        return max(ans1, ans2);
    }
};