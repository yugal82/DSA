// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visited, int n, int m){
        queue<pair<int,int>> q;
        q.push({i, j});
        visited[i][j] = 1;

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse in neighbours
            for(int deltaI = -1; deltaI <= 1; deltaI++){
                for(int deltaJ = -1; deltaJ <= 1; deltaJ++){
                    if(abs(deltaI) + abs(deltaJ) != 2){
                        int nRow = row + deltaI;
                        int nCol = col + deltaJ;

                        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                        grid[nRow][nCol] == '1' && visited[nRow][nCol] == 0){
                            visited[nRow][nCol] = 1;
                            q.push({nRow, nCol});
                        }
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // space complexity = O(n^2) + O(n^2)
        // time complexity = O(n^2)
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    count++;
                    bfs(grid, i, j, visited, n, m);
                }
            }
        }

        return count;
    }
};

int main(){
    Solution obj;
    vector<vector<char>> grid = {{'1','1','1','1','0'},
                                {'1','1','0','1','0'},
                                {'1','1','0','0','0'},
                                {'0','0','0','0','0'}};
    cout<<obj.numIslands(grid);

    return 0;
}