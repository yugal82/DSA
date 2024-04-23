// Given a triangle array, return the minimum path sum from top to bottom. For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>> &triangle, int i, int j, int n, vector<vector<int>> &dp){
        if(i == n-1) return triangle[n-1][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + solve(triangle, i+1, j, n, dp);
        int diagonal = triangle[i][j] + solve(triangle, i+1, j+1, n, dp);

        return dp[i][j] = min(down, diagonal);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        // return solve(triangle, 0, 0, n, dp);

        // tabulation
        for(int j = 0; j < n; j++) dp[n-1][j] = triangle[n-1][j];  // base case conversion, fill the last col 

        for(int i = n-2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, diagonal);
            }
        }

        return dp[0][0];
    }
};

int main(){
    Solution obj;
    vector<vector<int>> triangle = {{1}, {1, 5}, {4, 2, 1}, {4, 1, 8, 3}};
    obj.minimumTotal(triangle);
    return 0;
}