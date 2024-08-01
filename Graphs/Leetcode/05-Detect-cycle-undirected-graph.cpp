// Q] Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether it contains any cycle or not. Graph is in the form of adjacency list where adj[i] contains all the nodes ith node is having edge with.

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // TC - O(V + 2E)
    // SC - O(V) + O(V)
    bool bfs(vector<int> adj[], int visited[], int src){
        queue<pair<int, int>> q;
        q.push({src, -1});
        visited[src] = 1;
        
        while(!q.empty()){
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto it: adj[curr]){
                if(!visited[it]){
                    q.push({it, curr});
                    visited[it] = 1;
                }
                else if(visited[it] == 1 && it != parent) return true;
            }
        }
        
        return false;
    }
    
    // TC - O(V + 2E)
    // SC - O(V) + O(V)
    bool dfs(int src, vector<int> adj[], int visited[], int parent){
        visited[src] = 1;
        for(auto it:adj[src]){
            if(!visited[it]){
                if(dfs(it, adj, visited, src)) return true;
            }
            else if(it != parent) return true;
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // BFS Technique
        // int visited[V] = {0};
        // for(int i = 0; i < V; i++){
        //     if(!visited[i])
        //         if(bfs(adj, visited, i)) return true;
        // }
        
        // return false;
        
        
        // DFS Technique
        int visited[V] = {0};
        for(int i = 0; i < V; i++){
            if(visited[i] == 0)
                if(dfs(i, adj, visited, -1)) return true;
        }
        
        return false;
    }
};

int main(){
    int V = 5;
    vector<int> adj[] = {{2,3,1}, {0}, {0,4}, {0}, {2}};
    Solution obj;
    obj.isCycle(V, adj);

    return 0;
}