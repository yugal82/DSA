// Q] An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc]. To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color. Return the modified image after performing the flood fill.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>> &image, int sr, int sc, int color, vector<vector<int>> &visited){
        int n = image.size();
        int m = image[0].size();
        visited[sr][sc] = 1;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int startColor = image[sr][sc];

        int neighbourRow[] = {-1, 0, 1, 0};
        int neighbourCol[] = {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nRow = row + neighbourRow[i];
                int nCol = col + neighbourCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                visited[nRow][nCol] == 0 && image[nRow][nCol] == startColor){
                    image[nRow][nCol] = color;
                    visited[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> visited(image.size(), vector<int> (image[0].size(), 0));
        bfs(image, sr, sc, color, visited);
        image[sr][sc] = color;
        return image;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    obj.floodFill(image, 1, 1, 2);

    return 0;
}