// Q] A theif is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weight Wi and is of value Vi. Considering the constraints if the maximum weight that a knapsack can carry, you have to find and return the maximum value that a theif can generate by stealing items. Each item can be stolen any number of times within the constraints of max knapsack weight.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int recursion(int idx, int maxWeight, vector<int> &weight, vector<int> &value){
        if(idx == 0){
            if(weight[0] <= maxWeight) return int((maxWeight/weight[0])) * value[0];
            return 0;
        }

        int notTake = 0 + recursion(idx-1, maxWeight, weight, value);
        int take = INT_MIN;
        if(weight[idx] <= maxWeight) take = value[idx] + recursion(idx, maxWeight-weight[idx], weight, value);

        return max(take, notTake);
    }

    int memoization(int idx, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp){
        if(idx == 0){
            if(weight[0] <= maxWeight) return int((maxWeight/weight[0])) * value[0];
            return 0;
        }

        if(dp[idx][maxWeight] != -1) return dp[idx][maxWeight];

        int notTake = 0 + memoization(idx-1, maxWeight, weight, value, dp);
        int take = INT_MIN;
        if(weight[idx] <= maxWeight) take = value[idx] + memoization(idx, maxWeight-weight[idx], weight, value, dp);

        return dp[idx][maxWeight] = max(take, notTake);
    }

    int knapsack(vector<int> weight, vector<int> value, int maxWeight){
        int n = weight.size();
        // return recursion(n-1, maxWeight, weight, value);

        vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
        return memoization(n-1, maxWeight, weight, value, dp);
    }
};

int main(){
    Solution obj;
    vector<int> weight = {3,2,5};
    vector<int> value = {30,70,60};
    cout<<obj.knapsack(weight, value, 6);

    return 0;
}