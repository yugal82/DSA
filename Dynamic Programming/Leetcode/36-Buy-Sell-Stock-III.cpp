// Q] You are given an array prices where prices[i] is the price of a given stock on the ith day. Find the maximum profit you can achieve. You may complete at most two transactions. Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int idx, bool buy, vector<int> &prices, int k){
        if(idx == prices.size() || k == 0) return 0;

        int profit = 0;
        if(buy){
            // there will be 2 options - buy or not buy on the specific day
            int buyStock = -prices[idx] + recursion(idx+1, false, prices, k);
            int notBuyStock = 0 + recursion(idx+1, true, prices, k);
            profit = max(buyStock, notBuyStock);
        }
        else{
            // there will be again 2 options - sell or not sell on the specific day
            int sell = prices[idx] + recursion(idx+1, true, prices, k-1);
            int notSell = 0 + recursion(idx+1, false, prices, k);
            profit = max(sell, notSell);
        }
        return profit;
    }

    int memoization(int idx, int buy, vector<int> &prices,vector<vector<vector<int>>> &dp, int k){
        if(idx == prices.size() || k == 0) return 0;

        if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
        int profit = 0;
        if(buy){
            // there will be 2 options - buy or not buy on the specific day
            int buyStock = -prices[idx] + memoization(idx+1, 0, prices, dp, k);
            int notBuyStock = 0 + memoization(idx+1, 1, prices, dp, k);
            profit = max(buyStock, notBuyStock);
        }
        else{
            // there will be again 2 options - sell or not sell on the specific day
            int sell = prices[idx] + memoization(idx+1, 1, prices, dp, k-1);
            int notSell = 0 + memoization(idx+1, 0, prices, dp, k);
            profit = max(sell, notSell);
        }
        return dp[idx][buy][k] = profit;
    }

    int maxProfit(vector<int>& prices) {
        // since there are 3 changing parameters - idx, buy, and k, we define a 3D dp vector
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // return memoization(0, 1, prices, dp, 2);

        // base case can be omitted as we have already assigned all values of dp array to 0 and in base cases, we   are again assigning it to 0
        // for(int i = 0; i < prices.size(); i++)
        //     for(int j = 0; j <= 1; j++) dp[i][j][0] = 0;

        // for(int j = 0; j <= 1; j++)
        //     for(int k = 0; k <= 2; k++) dp[prices.size()][j][k] = 0;

        for(int idx = prices.size()-1; idx >= 0; idx--){
            for(int buy = 0; buy <= 1; buy++){
                for(int k = 1; k <= 2; k++){
                    int profit = 0;
                    if(buy){
                        // there will be 2 options - buy or not buy on the specific day
                        int buyStock = -prices[idx] + dp[idx+1][0][k];
                        int notBuyStock = 0 + dp[idx+1][1][k];
                        profit = max(buyStock, notBuyStock);
                    }
                    else{
                        // there will be again 2 options - sell or not sell on the specific day
                        int sell = prices[idx] + dp[idx+1][1][k-1];
                        int notSell = 0 + dp[idx+1][0][k];
                        profit = max(sell, notSell);
                    }
                    dp[idx][buy][k] = profit;
                }
            }
        }

        return dp[0][1][2];
    }
};

int main(){
    Solution obj;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout<<obj.maxProfit(prices);
    return 0;
}