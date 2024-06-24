// Q] You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day. Find and return the maximum profit you can achieve.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, bool buy, vector<int> &prices){
        if(idx == prices.size()) return 0;
        int profit = 0;
        if(buy){
            // there will be 2 options - buy or not buy on the specific day
            int buyStock = -prices[idx] + recursion(idx+1, false, prices);
            int notBuyStock = 0 + recursion(idx+1, true, prices);
            profit = max(buyStock, notBuyStock);
        }
        else{
            // there will be again 2 options - sell or not sell on the specific day
            int sell = prices[idx] + recursion(idx+1, true, prices);
            int notSell = 0 + recursion(idx+1, false, prices);
            profit = max(sell, notSell);
        }

        return profit;
    }

    int memoization(int idx, bool buy, vector<int> &prices,vector<vector<int>> &dp){
        if(idx == prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if(buy){
            // there will be 2 options - buy or not buy on the specific day
            int buyStock = -prices[idx] + memoization(idx+1, false, prices, dp);
            int notBuyStock = 0 + memoization(idx+1, true, prices, dp);
            profit = max(buyStock, notBuyStock);
        }
        else{
            // there will be again 2 options - sell or not sell on the specific day
            int sell = prices[idx] + memoization(idx+1, true, prices, dp);
            int notSell = 0 + memoization(idx+1, false, prices, dp);
            profit = max(sell, notSell);
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        // return memoization(0, 1, prices, dp);

        dp[prices.size()][0] = 0;
        dp[prices.size()][1] = 0;

        for(int i = prices.size()-1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                int profit = 0;
                if(j == 1){
                    // there will be 2 options - buy or not buy on the specific day
                    int buyStock = -prices[i] + dp[i+1][0];
                    int notBuyStock = 0 + dp[i+1][1];
                    profit = max(buyStock, notBuyStock);
                }
                else{
                    // there will be again 2 options - sell or not sell on the specific day
                    int sell = prices[i] + dp[i+1][true];
                    int notSell = 0 + dp[i+1][false];
                    profit = max(sell, notSell);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};

int main(){
    Solution obj;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<obj.maxProfit(prices);
    return 0;
}