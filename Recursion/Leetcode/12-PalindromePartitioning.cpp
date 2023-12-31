// Question - Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void solve(string s, int partitionIdx, vector<string> &path, vector<vector<string>> &ans){
        if(partitionIdx == s.size()){
            ans.push_back(path);
            return;
        }

        for(int i = partitionIdx; i < s.size(); ++i){
            if(isPalindrome(s, partitionIdx, i)){
                path.push_back(s.substr(partitionIdx, i - partitionIdx + 1));
                solve(s, i+1, path, ans);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s, 0, path, ans);

        return ans;
    }
};

int main(){
    string s = "aabb";
    Solution obj;
    vector<vector<string>> ans = obj.partition(s);
    for(auto x : ans){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}