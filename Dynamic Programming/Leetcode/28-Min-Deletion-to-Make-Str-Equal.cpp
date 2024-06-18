// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same. In one step, you can delete exactly one character in either string.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string s, string t, int n, int m){
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int len = lcs(word1, word2, n, m);
        return n + m - 2*len;
    }
};

int main(){
    Solution obj;
    string s = "abcde";
    string t = "ace";
    cout<<obj.minDistance(s, t);
    return 0;
}