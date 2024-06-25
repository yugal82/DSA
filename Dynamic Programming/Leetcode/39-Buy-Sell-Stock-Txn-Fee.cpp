// Q] You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions: After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, bool buy, vector<int> &prices, int fee){
        if(idx == prices.size()) return 0;

        int profit = 0;
        if(buy){
            // there will be 2 options - buy or not buy on the specific day
            int buyStock = -prices[idx] + recursion(idx+1, false, prices, fee);
            int notBuyStock = 0 + recursion(idx+1, true, prices, fee);
            profit = max(buyStock, notBuyStock);
        }
        else{
            // there will be again 2 options - sell or not sell on the specific day
            int sell = prices[idx] + recursion(idx+1, true, prices, fee) - fee;
            int notSell = 0 + recursion(idx+1, false, prices, fee);
            profit = max(sell, notSell);
        }

        return profit;
    }

    int memoization(int idx, int buy, vector<int> &prices,vector<vector<int>> &dp, int fee){
        if(idx == prices.size()) return 0;

        if(dp[idx][buy] != -1) return dp[idx][buy];

        int profit = 0;
        if(buy){
            // there will be 2 options - buy or not buy on the specific day
            int buyStock = -prices[idx] + memoization(idx+1, 0, prices, dp, fee);
            int notBuyStock = 0 + memoization(idx+1, 1, prices, dp, fee);
            profit = max(buyStock, notBuyStock);
        }
        else{
            // there will be again 2 options - sell or not sell on the specific day
            int sell = prices[idx] + memoization(idx+1, 1, prices, dp, fee) - fee;
            int notSell = 0 + memoization(idx+1, 0, prices, dp, fee);
            profit = max(sell, notSell);
        }

        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        // return recursion(0, true, prices, fee);
        vector<vector<int>>dp (prices.size()+1, vector<int>(2, 0));
        // return memoization(0, 1, prices, dp, fee);

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
                    int sell = prices[i] + dp[i+1][1] - fee;
                    int notSell = 0 + dp[i+1][0];
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
    vector<int> prices = {1,3,2,8,4,9};
    cout<<obj.maxProfit(prices, 2);
    return 0;
}