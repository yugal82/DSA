// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin. The answer is guaranteed to fit into a signed 32-bit integer.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(idx == 0){
            if(amount % coins[idx] == 0) return 1;
            else return 0;
        }
        
        if(dp[idx][amount] != -1) return dp[idx][amount];

        // do not take the coin
        int notTake = recursion(idx-1, amount, coins, dp);
        // take the coin
        int take = 0;
        if(coins[idx] <= amount) take = recursion(idx, amount-coins[idx], coins, dp);

        return dp[idx][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return recursion(n-1, amount, coins, dp);
    }
};

int main(){
    Solution obj;
    vector<int> coins = {1,2,5};
    int amount = 11;
    obj.change(amount, coins);
    return 0;
}