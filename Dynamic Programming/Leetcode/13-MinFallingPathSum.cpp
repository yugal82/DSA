// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &matrix, int n, vector<vector<int>> &dp){
        if(j < 0 || j > n-1) return 1e9;
        if(i == 0) return matrix[0][j];

        if(dp[i][j] != -1) return dp[i][j];

        int up = matrix[i][j] + solve(i-1, j, matrix, n, dp);
        int leftDiag = matrix[i][j] + solve(i-1, j-1, matrix, n, dp);
        int rightDiag = matrix[i][j] + solve(i-1, j+1, matrix, n, dp);

        return dp[i][j] = min(up, min(leftDiag, rightDiag));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        // for(int j = 0; j < n; j++){
        //     int pathSum = solve(n-1, j, matrix, n, dp);
        //     mini = min(mini, pathSum);
        // }

        // base case, filling the all psbl start position values in dp vector
        for(int j = 0; j < n; j++) dp[n-1][j] = matrix[n-1][j];
        
        for(int i = n-2; i >= 0; i--){
            for(int j = 0; j < n; j++){
                int up = dp[i+1][j];
                int leftDiag, rightDiag;
                if(j > 0) leftDiag = dp[i+1][j-1];
                else leftDiag = 1e8;

                if(j < n-1) rightDiag = dp[i+1][j+1];
                else rightDiag = 1e8;

                dp[i][j] = matrix[i][j] + min(up, min(leftDiag, rightDiag));
            }
        }
        int mini = 1e8;
        for(int i = 0; i < n; i++) 
            mini = min(mini, dp[0][i]);

        return mini;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> matrix = {{2,1,3}, {6,5,4}, {7,8,9}};
    obj.minFallingPathSum(matrix);
    return 0;
}