// Q] You are climbing a staircase. It takes n steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 1 || n == 0) return 1;

        if(dp[n] != -1) return dp[n];
        else return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }

    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }

    // Tabulation
    // int climbStairs(int n){
    //     int prev2 = 1, prev1 = 1;
    //     for(int i = 2; i <= n; i++){
    //         int curr = prev1 + prev2;
    //         prev2 = prev1;
    //         prev1 = curr;
    //     }

    //     return prev1;
    // }


    // for recursion, it gives TLE for bigger 'n'. So let's convert the solution to DP (memoization)
    // int climbStairs(int n) {
    //     if(n == 0 || n == 1) return 1;

    //     return climbStairs(n-1) + climbStairs(n-2);
    // }
};