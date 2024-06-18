// Given two strings text1 and text2, print the longest common subsequence. 

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lcs(int i, int j, string s, string t, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j] = 1 + lcs(i-1, j-1, s, t, dp);
        return dp[i][j] = max(lcs(i-1, j, s, t, dp), lcs(i, j-1, s, t, dp));
    }

    string printLCS(string s, string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i = n, j = m;
        string ans = "";

        while(i > 0 && j > 0){
            if(s[i-1] == t[j-1]){
                ans.push_back(s[i-1]);
                i--; 
                j--;
            }
            else if(dp[i-1] > dp[j-1]) i--;
            else j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    Solution obj;
    string s = "abcdesgtdax";
    string t = "acegaggncax";
    cout<<obj.printLCS(s, t);
    return 0;
}