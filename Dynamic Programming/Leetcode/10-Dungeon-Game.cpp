// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.
// The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.
// Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).
// To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.
// Return the knight's minimum initial health so that he can rescue the princess.
// Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &dungeon, int row, int col, vector<vector<int>> &dp){
        if(row > m || col > n) return INT_MIN;
        if(row == m && col == n) {
            if(dungeon[row][col] > 0) return 0;
            else return dungeon[row][col];
        };

        if(dp[row][col] != -1) return dp[row][col];

        int down = solve(m, n, dungeon, row+1, col, dp);
        int right = solve(m, n, dungeon, row, col+1, dp);
        int maxi = dungeon[row][col] + max(down, right);
        if(maxi > 0) maxi = 0;
        
        return dp[row][col] = maxi;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return 1 + abs(solve(m-1, n-1, dungeon, 0, 0, dp));
    }
};

int main(){
    Solution obj;
    vector<vector<int>> dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    obj.calculateMinimumHP(dungeon);
    return 0;
}