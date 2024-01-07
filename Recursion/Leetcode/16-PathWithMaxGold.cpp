// Question - In a gold mine grid of size m x n, each cell in this mine has an integer representing the amount of gold in that cell, 0 if it is empty.

// Return the maximum amount of gold you can collect under the conditions:
// Every time you are located in a cell you will collect all the gold in that cell.
// From your position, you can walk one step to the left, right, up, or down.
// You can't visit the same cell more than once.
// Never visit a cell with 0 gold.
// You can start and stop collecting gold from any position in the grid that has some gold.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>> &grid, int row, int col, int &ans, int &goldSum, vector<vector<int>> &isVisited){
        goldSum += grid[row][col];

        // go down
        if(row+1 < grid.size() && grid[row+1][col] != 0 && !isVisited[row+1][col]){
            isVisited[row][col] = 1;
            solve(grid, row+1, col, ans, goldSum, isVisited);
            
            // backtrack 
            isVisited[row][col] = 0;
        }

        // go left
        if(col -1 >= 0 && grid[row][col-1] != 0 && !isVisited[row][col-1]){
            isVisited[row][col] = 1;
            solve(grid, row, col-1, ans, goldSum, isVisited);

            // backtrack
            isVisited[row][col] = 0;
        }

        // go right
        if(col +1 < grid[0].size() && grid[row][col+1] != 0 && !isVisited[row][col+1]){
            isVisited[row][col] = 1;    
            solve(grid, row, col+1, ans, goldSum, isVisited);

            // backtrack
            isVisited[row][col] = 0;
        }

        // go up
        if(row -1 >= 0 && grid[row-1][col] != 0 && !isVisited[row-1][col]){
            isVisited[row][col] = 1;
            solve(grid, row-1, col, ans, goldSum, isVisited);

            // backtrack
            isVisited[row][col] = 0;
        }

        if(ans < goldSum){
            ans = goldSum;
        }
        
        // backtrack
        goldSum -= grid[row][col];

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> isVisited(grid.size(), vector<int> (grid[0].size(), 0));
        int goldSum = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0){
                    solve(grid, i, j, ans, goldSum, isVisited);
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
    int ans = obj.getMaximumGold(grid);
    cout<<ans;

    return 0;
}

