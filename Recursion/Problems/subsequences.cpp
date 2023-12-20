// Question - Print the subsequences of a given array
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void evaluateSubsequence(int idx, vector<int> &nums, vector<int> &subseqArr, vector<vector<int>> &ans){
    if(idx == nums.size()){
        ans.push_back(subseqArr);
        return;
    }

    // take the element at a particular index
    subseqArr.push_back(nums[idx]);
    evaluateSubsequence(idx+1, nums, subseqArr, ans);

    // do not take the element at a particular index
    // since we want to not take the element at a particular index, and in the previous call we have pushed/added that element, we first remove the element and then we make a function call for "dont take"
    subseqArr.pop_back();
    evaluateSubsequence(idx+1, nums, subseqArr, ans);
}

int main(){
    vector<int> nums = {3,1,2,5};
    vector<int> subseqArr;
    vector<vector<int>> ans;

    evaluateSubsequence(0, nums, subseqArr, ans);

    cout<<"The number of subsequences are: "<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        if(ans[i].size() == 0) cout<<"{}";
        cout<<endl;
    }
    return 0;
}