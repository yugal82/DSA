// Question - The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other. Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order. Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &checkLeft, vector<int> &upperDiagonal, vector<int> &lowerDiagonal){
        // base case
        if(col == n){
            ans.push_back(board);
            return;
        }

        // here we are trying to fill each row at the current column 'col'
        for(int row = 0; row < n; row++){
            if(checkLeft[row] == 0 && upperDiagonal[row+col] == 0 && lowerDiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                checkLeft[row] = 1;
                upperDiagonal[row+col] = 1;
                lowerDiagonal[n-1+col-row] = 1;
                solve(col+1, n, board, ans, checkLeft, upperDiagonal, lowerDiagonal);
                board[row][col] = '.';
                checkLeft[row] = 0;
                upperDiagonal[row+col] = 0;
                lowerDiagonal[n-1+col-row] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i < n; i++) board[i] = s;
        vector<int> checkLeft(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        solve(0, n, board, ans, checkLeft, upperDiagonal, lowerDiagonal);

        return ans;
    }
};

int main(){
    int n = 4;
    Solution obj;
    vector<vector<string>> ans = obj.solveNQueens(n);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}