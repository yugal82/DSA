// Question - Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    void findCombinationSum(vector<int> &nums, int target, int idx, vector<int> &subSeqArr, vector<vector<int>> &ans){
        
        if(idx == nums.size()){
            if(target == 0) ans.push_back(subSeqArr);
            return;
        }

        // take the particular element in the subsequence.
        if(nums[idx] <= target){
            subSeqArr.push_back(nums[idx]);
            findCombinationSum(nums, target-nums[idx], idx, subSeqArr, ans);
            subSeqArr.pop_back();
        }

        // do not take the particular element in the subsequence.
        findCombinationSum(nums, target, idx+1, subSeqArr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> subSeqArr;
        vector<vector<int>> ans;
        findCombinationSum(candidates, target, 0, subSeqArr, ans);

        return ans;    
    }
};

int main(){
    Solution obj;
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = obj.combinationSum(candidates, target);
    for(auto i:ans){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
}