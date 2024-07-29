 #include<bits/stdc++.h>
 using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> bfs, visited(V, 0);
        q.push(0);
        visited[0] = 1;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            bfs.push_back(current);
            for(auto it: adj[current]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        
        return bfs;
    }
};

int main(){
    int V = 5;
    vector<int> adj[] = {{2,3,1} , {0}, {0,4}, {0}, {2}};
    Solution obj;
    obj.bfsOfGraph(V, adj);

    return 0;
}