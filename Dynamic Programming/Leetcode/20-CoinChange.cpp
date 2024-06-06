// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1. You may assume that you have an infinite number of each kind of coin

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(idx == 0){
            if(amount % coins[idx] == 0) return amount/coins[idx];
            else return 1e9;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];

        // do not take the coin
        int notTake = 0 + recursion(idx-1, amount, coins, dp);
        // take the coin
        int take = INT_MAX;
        if(coins[idx] <= amount) take = 1 + recursion(idx, amount-coins[idx], coins, dp);

        return dp[idx][amount] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int minCoins = recursion(n-1, amount, coins, dp);
        if(minCoins >= 1e9) return -1;
        return minCoins;
    }
};

int main(){
    Solution obj;
    vector<int> coins = {1,2,5};
    int amount = 11;
    obj.coinChange(coins, amount);
    return 0;
}