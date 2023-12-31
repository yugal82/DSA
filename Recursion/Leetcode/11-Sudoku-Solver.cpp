// Question - Write a program to solve a Sudoku puzzle by filling the empty cells. A sudoku solution must satisfy all of the following rules:
    // Each of the digits 1-9 must occur exactly once in each row.
    // Each of the digits 1-9 must occur exactly once in each column.
    // Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
    // The '.' character indicates empty cells.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>> &board){
        for(int i = 0; i < 9; i++){
            if(board[row][i] == c) return false;

            if(board[i][col] == c) return false;

            if(board[(3*(row/3) + i/3)][(3*(col/3) + i%3)] == c) return false;
        }
        
        return true;
    }

    bool solve(vector<vector<char>> &board){
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // if the position is empty, then only we try to fill it
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        if(isValid(i, j, c, board)){
                            board[i][j] = c;

                            if(solve(board) == true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }

                    return false;
                }

            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


int main(){
    Solution s;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                   {'6','.','.','1','9','5','.','.','.'},
                                   {'.','9','8','.','.','.','.','6','.'},
                                   {'8','.','.','.','6','.','.','.','3'},
                                   {'4','.','.','8','.','3','.','.','1'},
                                   {'7','.','.','.','2','.','.','.','6'},
                                   {'.','6','.','.','.','.','2','8','.'},
                                   {'.','.','.','4','1','9','.','.','5'},
                                   {'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(board);
    for(int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[0].size(); j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
