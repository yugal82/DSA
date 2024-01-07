// Question - The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of nums. 
// Note: Subsets with the same elements should be counted multiple times.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:

    void solve(vector<int> &nums, int idx, vector<int> &subsets, int &xorSum){
        // base condition
        if(idx == nums.size()){
            int sum = 0;
            for(int i = 0; i < subsets.size(); i++){
                sum = sum ^ subsets[i];
            }

            xorSum += sum;
            return;
        }

        // include current element in the subset
        subsets.push_back(nums[idx]);
        solve(nums, idx+1, subsets, xorSum);

        // do not include the current element in the subset
        subsets.pop_back();
        solve(nums, idx+1, subsets, xorSum);

    }

    int subsetXORSum(vector<int>& nums) {
        int xorSum = 0;
        vector<int> subsets;
        solve(nums, 0, subsets, xorSum);

        return xorSum;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,3};
    int ans = obj.subsetXORSum(nums);
    cout<<ans;

    return 0;
}