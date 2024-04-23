// Q] Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return grid[m][n];
        if(m < 0 || n < 0) return 1e9;

        if(dp[m][n] != -1) return dp[m][n];

        int up = grid[m][n] + solve(m-1, n, grid, dp);
        int left = grid[m][n] + solve(m, n-1, grid, dp);
        return dp[m][n] = min(up, left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        // Memoization
        // return solve(m-1, n-1, grid, dp);

        // Tabulation
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = grid[i][j] + dp[i-1][j];
                    else up = 1e9;

                    if(j > 0) left = grid[i][j] + dp[i][j-1];
                    else left = 1e9;

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];

    }
};

int main(){
    Solution obj;
    vector<vector<int>> dungeon = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    obj.minPathSum(dungeon);
    return 0;
}