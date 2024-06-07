// Q] Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int recursion(int idx, int n, vector<int> &price){
        if(idx == 0){
            return n*price[idx];
        }

        // do not cut the rod
        int notCut = 0 + recursion(idx-1, n, price);
        // cut the rod
        int cut = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= n) cut = price[idx] + recursion(idx, n-rodLength, price);

        return max(notCut, cut);
    }
    
    int memoization(int idx, int n, vector<int> &price, vector<vector<int>> &dp){
        if(idx == 0){
            return n*price[idx];
        }

        // do not cut the rod
        int notCut = 0 + memoization(idx-1, n, price, dp);
        // cut the rod
        int cut = INT_MIN;
        int rodLength = idx+1;
        if(rodLength <= n) cut = price[idx] + memoization(idx, n-rodLength, price, dp);

        return max(notCut, cut);
    }
    int cutRod(vector<int> &price, int n){
        // return recursion(price.size()-1, n, price);
        vector<vector<int>> dp(price.size(), vector<int>(n+1, -1));
        return memoization(price.size()-1, n, price, dp);
    }
};

int main(){
    Solution obj;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = 8;
    cout<<obj.cutRod(price, n);
    return 0;
}