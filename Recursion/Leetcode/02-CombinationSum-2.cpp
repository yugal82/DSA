// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target. Each number in candidates may only be used once in the combination. 
// Note: The solution set must not contain duplicate combinations.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void solve(vector<int>& nums, int target, int idx, vector<int> subSeqArr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(subSeqArr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > target)
                break;

            subSeqArr.push_back(nums[i]);
            solve(nums, target - nums[i], i + 1, subSeqArr, ans);
            subSeqArr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> subSeqArr;
        solve(candidates, target, 0, subSeqArr, ans);

        return ans;
    }
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    vector<vector<int>> ans = s.combinationSum2(candidates, target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}