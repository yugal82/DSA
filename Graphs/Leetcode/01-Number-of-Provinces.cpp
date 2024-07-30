// Q] There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c. A province is a group of directly or indirectly connected cities and no other cities outside of the group. You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 #include<bits/stdc++.h>
 using namespace std;

class Solution {
public:
    void dfs(int current, vector<int> adjLst[], vector<int> &visited){
        visited[current] = 1;
        for(auto it: adjLst[current]){
            if(visited[it] == 0) dfs(it, adjLst, visited);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjLst[V+1];
        
        // adjacency matrix to adjacency list
        for(int u = 0; u < V; u++){
            for(int v = 0; v < V; v++){
                if(isConnected[u][v] == 1 && u != v){
                    adjLst[u+1].push_back(v+1);
                    // adjLst[v].push_back(u);
                }
            }
        }

        vector<int> visited(V+1, 0);
        int count = 0;
        for(int i = 1; i <= V; i++){
            if(visited[i] == 0){
                count++;
                dfs(i, adjLst, visited);
            }
        }

        return count;
    }
};

int main(){
    int V = 5;
    Solution obj;
    vector<vector<int>> isConnected = {{1,1,0}, {1,1,0}, {0,0,1}};
    cout<<obj.findCircleNum(isConnected);

    return 0;
}