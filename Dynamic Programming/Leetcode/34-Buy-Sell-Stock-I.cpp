// Q] You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0], profit = 0;
        for(int i = 0; i < prices.size(); i++){
            // if the cost is -ve, that means it is loss, otherwise it is profit.
            // cost = sellingPrice - buyingPrice. mini indicates the minimum buying price. 
            int cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;

        // int profit = 0;
        // for(int i = 0; i < prices.size(); i++){
        //     int buyingPrice = prices[i];
        //     for(int j = i; j < prices.size(); j++){
        //         int cost = prices[j] - buyingPrice;
        //         profit = max(profit, cost);
        //     }
        // }

        // return profit;
    }
};

int main(){
    Solution obj;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<obj.maxProfit(prices);
    return 0;
}