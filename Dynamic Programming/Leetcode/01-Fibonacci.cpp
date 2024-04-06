#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // tabulation technique
        // TC - O(n) ----- SC - O(1)
        int prev1 = 0, prev = 1;
        for(int i = 2; i <= n; i++){
            int curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }

        return prev;
    }
};

int main(){
    Solution obj;
    cout<<obj.fib(5);

    return 0;
}