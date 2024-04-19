// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>> &dp){
        // base condition
        if(m >= 0 && n >= 0 && obstacleGrid[m][n] == 1) return 0; // stone found.
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0; // out of bounds

        if(dp[m][n] != -1) return dp[m][n];

        int up = solve(obstacleGrid, m-1, n, dp);
        int left = solve(obstacleGrid, m, n-1, dp);

        return dp[m][n] = up + left;
    }

    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m = obstacleGrid.size();
    //     int n = obstacleGrid[0].size();
    //     vector<vector<int>> dp(m, vector<int> (n, -1));

    //     if(obstacleGrid[m-1][n-1] != 1){
    //         return solve(obstacleGrid, m-1, n-1, dp);
    //     }
    //     return 0;
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)
            return 0;
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[0][0] = 1;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[0][0] = 1;
                else{
                    if(obstacleGrid[i][j] != 1){
                        int up = 0, left = 0;
                        if(i > 0) up = dp[i-1][j];
                        if(j > 0) left = dp[i][j-1];
                    
                        dp[i][j] = up + left;
                    }
                }
            }
        }

        return dp[m-1][n-1];
    }
};

int main(){
    Solution obj;
    vector<vector<int>> obstacle = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int ans = obj.uniquePathsWithObstacles(obstacle);
    cout<<ans;
    return 0;
}