// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>> q;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }

        int neighbourRows[] = {-1, 0, 1, 0};
        int neighbourCols[] = {0, 1, 0, -1};
        int time = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            time = max(time, tm);
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + neighbourRows[i];
                int ncol = col + neighbourCols[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] != 2 &&
                grid[nrow][ncol] == 1){
                    q.push({{nrow, ncol}, tm + 1});
                    visited[nrow][ncol] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1) return -1;
            }
        }
        return time;

        // SC -> O(n*m)
        // TC -> O(n*m)
    }
};


int main(){
    Solution obj;
    vector<vector<int>> grid = {{0,1,1,2}, {0,1,0,1}, {1,1,0,1}, {2,1,0,0}};
    cout<<obj.orangesRotting(grid);

    return 0;
}
