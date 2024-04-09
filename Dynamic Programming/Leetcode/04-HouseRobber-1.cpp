// Q] You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police

// Q] MAXIMUM SUM OF NON ADJACENT ELEMENTS - (in note book)

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    // NOW THIS IS A RECURESIVE CODE WHICH HAS OVERLAPPING SUBPROBLEMS. 
    // THIS MEANS THE CODE COMPUTES VALUES OF THE SAME FUNCTION CALL AGAIN AND AGAIN.
    // TO AVOID THIS, WE USE DP TECHNIQUE - MEMOIZATION
    // int solve(vector<int> &nums, int idx){
    //     // base case
    //     if(idx == 0) return nums[idx];
    //     if(idx < 0) return 0;

    //     // rob the current house
    //     // if we want to rob the house, add the amount of money in the present house.
    //     // Since we have multiple houses to rob, we recursively rob the house.
    //     //  However, there is one constraint that no adjancent houses can be robbed.
    //     // Therefore, we directly jump to (idx-2)th house.
    //     int pick = nums[idx] + solve(nums, idx-2);

        
    //     // do not rob the current house
    //     // if we do not want to rob the current house, we do not add the money i.e 0 
    //     // and as we have not robbed this house, we jump to the adjacent house i.e (idx -1)th house.
    //     int notpick = 0 + solve(nums, idx-1);

    //     return max(pick, notpick);
    // }
    // int rob(vector<int>& nums) {
    //     return solve(nums, nums.size()-1);
    // }


    // -----------------------------------------------------------------------------------------------
    // MEMOIZATION - 
    // int solve(vector<int> &nums, int n, vector<int> &dp){
    //     if(n == 0) return nums[n];
    //     if(n < 0) return 0;

    //     // check if subproblem has already been solved previously. If yes, then directly return the computed value
    //     if(dp[n] != -1) return dp[n];
    //     else{
    //         int robHouse = nums[n] + solve(nums, n-2, dp);
    //         int notRobHouse = 0 + solve(nums, n-1, dp);

    //         return dp[n] = max(robHouse, notRobHouse); 
    //     }
    // }
    // int rob(vector<int> &nums){
    //     int n = nums.size();
    //     vector<int> dp(n+1, -1);
    //     return solve(nums, n-1, dp);
    // }


    // -----------------------------------------------------------------------------------------------
    // TABULATION - 
    int rob(vector<int> &nums){
        // for tabulation, convert the base case of memoization to tabulation initial values
        int n = nums.size();
        int prev2 = 0, prev1 = nums[0];
        for(int i = 1; i < n; i++){
            int robHouse = nums[i];
            if(i > 1) robHouse += prev2;
            int notRobHouse = 0 + prev1;
            int curr = max(robHouse, notRobHouse);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,5,8,2,9};
    obj.rob(nums);
    return 0;
}