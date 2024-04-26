// Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
// A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp, int prevCol){
        if(i == grid.size()-1) return grid[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e8;
        for(int idx = 0; idx < grid.size(); idx++){
            if(prevCol != idx) mini = min(mini, solve(i+1, idx, grid, dp, idx));
        }

        return dp[i][j] = grid[i][j] +  mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        int mini = 1e8;
        for(int j = 0; j < n; j++){
            int pathSum = solve(0, j, grid, dp, j);
            mini = min(mini, pathSum);
        }

        return mini;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid =  {{-73,61,43,-48,-36}, {3,30,27,57,10}, {96,-76,84,59,-15}, {5,-49,76,31,-7}, {97,91,61,-46,67}};
    obj.minFallingPathSum(grid);
    return 0;
}

