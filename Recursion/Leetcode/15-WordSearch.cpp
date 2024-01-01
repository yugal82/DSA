// Question - Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// Filed for this test case
//  board = [["a","a"]]
//  word = "aa"
// class Solution {
// public:
//     bool solve(vector<vector<char>> &board, int row, int col, string word, vector<vector<int>> &isVisited, string &output){
//         // jitna bhi output string bana hai, utna size ka word compare karo with output string.
//         // For eg. output = "ABF" and word = "ABCCED". So now only check first 3 characters of both strings. If both are equal, then continue else return false
//         if(output.size() > 0 && output != word.substr(0, output.size())) return false;

//         // base condition
//         if(output == word) return true;

//         // go down
//         if(row + 1 < board.size() && !isVisited[row+1][col]){
//             isVisited[row][col] = 1;
//             output.push_back(board[row][col]);
//             if(solve(board, row+1, col, word, isVisited, output))
//                 return true;

//             // if false, then backtrack
//             isVisited[row][col] = 1;
//             output.pop_back();
//         }

//         // go left
//         if(col -1 >= 0 && !isVisited[row][col-1]){
//             isVisited[row][col] = 1;
//             output.push_back(board[row][col]);
//             if(solve(board, row, col-1, word, isVisited, output))
//                 return true;

//             // if false, then backtrack
//             isVisited[row][col] = 1;
//             output.pop_back();
//         }

//         // go right
//         if(col +1 < board[0].size() && !isVisited[row][col+1]){
//             isVisited[row][col] = 1;
//             output.push_back(board[row][col]);
//             if(solve(board, row, col+1, word, isVisited, output))
//                 return true;

//             // if false, then backtrack
//             isVisited[row][col] = 1;
//             output.pop_back();
//         }

//         // go up
//         if(row -1 >= 0 && !isVisited[row-1][col]){
//             isVisited[row][col] = 1;
//             output.push_back(board[row][col]);
//             if(solve(board, row-1, col, word, isVisited, output))
//                 return true;

//             // if false, then backtrack
//             isVisited[row][col] = 1;
//             output.pop_back();
//         }

//         return false;
//     }

//     bool exist(vector<vector<char>>& board, string word) {
//         int row = board.size();
//         int col = board[0].size();

//         if(row == 1 && col == 1){
//             string boardChar = "";
//             boardChar.push_back(board[row-1][col-1]);
//             if(word == boardChar) return true;
//             else return false;
//         }
//         bool ans;
//         string output = "";
//         vector<vector<int>> isVisited(row, vector<int> (col, 0));
//         for(int i = 0; i < row; i++){
//             for(int j = 0; j < col; j++){
//                 ans = solve(board, i, j, word, isVisited, output);
//             }
//         }
//         return ans;
        
//     }
// };


class Solution {
public:
    bool solve(vector<vector<char>> &board, int row, int col, string word, int index){
        // base condition
        if(index == word.size()) return true;

        // to check if the indexes are valid, if not, it will give runtime error
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '*';
        if(solve(board, row+1, col, word, index+1))
            return true;

        if(solve(board, row, col-1, word, index+1))
            return true;
        
        if(solve(board, row, col+1, word, index+1))
            return true;

        if(solve(board, row-1, col, word, index+1))
            return true;
        
        board[row][col] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(solve(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
        
    }
};

int main(){
    Solution obj;
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'} , {'A','D','E','E'}};
    string word = "ABCCED";
    cout << obj.exist(board, word) << endl;
    return 0;
    
}