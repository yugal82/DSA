 #include<bits/stdc++.h>
 using namespace std;

class Solution {
  public:
    void traverse(int current, vector<int> adj[], vector<int> &visited, vector<int> &dfs){
        visited[current] = 1;
        dfs.push_back(current);
        for(auto it: adj[current]){
            if(!visited[it]) traverse(it, adj, visited, dfs);
        }
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), dfs;
        traverse(0, adj, visited, dfs);
        
        return dfs;
    }
};


int main(){
    int V = 5;
    vector<int> adj[] = {{2,3,1} , {0}, {0,4}, {0}, {2}};
    Solution obj;
    obj.dfsOfGraph(V, adj);

    return 0;
}