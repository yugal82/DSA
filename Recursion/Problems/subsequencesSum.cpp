// Question - Print the subsequences that add up to the target
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void subsequencesSum(vector<int> &arr, int target, int idx, int sum, vector<int> &subSeqArr){
    if(idx == arr.size()){
        if(sum == target){
            for(auto it:subSeqArr)
                cout<<it<<" ";

            cout<<endl;
        }
        return;
    }

    // take the current element
    subSeqArr.push_back(arr[idx]);
    sum += arr[idx];
    subsequencesSum(arr, target, idx+1, sum, subSeqArr);

    // dont take the current element
    sum -= arr[idx];
    subSeqArr.pop_back();
    subsequencesSum(arr, target, idx+1, sum, subSeqArr);
}

int main(){
    vector<int> arr = {1,2,1,1};
    int target = 3;
    vector<int> subSeqArr;

    subsequencesSum(arr, target, 0, 0, subSeqArr);
    return 0;
}