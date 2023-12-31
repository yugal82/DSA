// Question - Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(int openLeft, int closeLeft, string &parenthesis, vector<string> &ans){
        // base condition
        if(openLeft == 0 && closeLeft == 0){
            ans.push_back(parenthesis);
            return;
        }
        
        if(openLeft > 0){
            parenthesis.push_back('(');
            solve(openLeft-1, closeLeft, parenthesis, ans);
            parenthesis.pop_back();
        }

        if(closeLeft > openLeft){
            parenthesis.push_back(')');
            solve(openLeft, closeLeft-1, parenthesis, ans);
            parenthesis.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string parenthesis = "";
        solve(n, n, parenthesis, ans);

        return ans;
    }
};

int main(){
    int n = 3;
    Solution obj;
    vector<string> ans = obj.generateParenthesis(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}