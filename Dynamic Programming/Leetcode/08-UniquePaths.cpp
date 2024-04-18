// Q] There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time. Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // MEMOIZATION
    int solve(int m, int n, vector<vector<int>> &dp){
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int down = solve(m-1, n, dp);
        int right = solve(m, n-1, dp);

        return dp[m][n] = down + right;
    }

    // TABULATION
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 0));
        // return solve(m-1, n-1, dp);
        
        dp[0][0] = 1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[0][0] = 1;
                else{
                    int up = 0, left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    
                    dp[i][j] = up + left;
                }
            }
        }

        return dp[m-1][n-1];
        
    }
};

int main(){
    Solution obj;
    int ans = obj.uniquePaths(3,3);
    cout<<ans;
    return 0;
}