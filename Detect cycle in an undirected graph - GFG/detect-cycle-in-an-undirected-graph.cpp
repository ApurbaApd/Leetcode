//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    private:
    bool detect(int start, vector<int>adj[], int vis[]){
        vis[start]=1;
        queue<pair<int,int>>q;
        q.push({start,-1});//{node, parent}
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int parent = it.second;
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it, node});
                }
                else if(parent != it)
                  return 1;
            }
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis))
                   return 1;
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends