// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps. You can either start from the step with index 0, or the step with index 1. Return the minimum cost to reach the top of the floor.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int idx, int n, vector<int> &cost, vector<int> &dp){
        if(idx >= n-1) return 0;
        
        if(dp[idx] != -1) return dp[idx];
        int one = cost[idx] + solve(idx+1, n, cost, dp);
        int two = cost[idx+1] + solve(idx+2, n, cost, dp);
        
        return dp[idx] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -0);
        // return solve(0, n, cost, dp);

        for(int i = n-2; i >= 0; i--){
            int one = cost[i] + dp[i+1];
            int two = cost[i+1] + dp[i+2];
            
            dp[i] = min(one, two);
        }
        return dp[0];
    }
};

int main(){
    Solution obj;
    vector<int> cost = {20,15,10};
    obj.minCostClimbingStairs(cost);
    return 0;
}