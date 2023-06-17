//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here//
        int V=n;
        vector<int> adj[V]; // Adjacency list to represent the prerequisites

        // Build the adjacency list
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // Add prerequisite edge from it[1] to it[0]
        }

        vector<int> indegree(V, 0); // Store the indegree of each node

        // Calculate the indegree of each node by traversing the adjacency list
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q; // Queue to store nodes with indegree 0

        // Add nodes with indegree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo; // Topological ordering of nodes

        // Perform modified BFS (topological sort)
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node); // Add the node to the topological ordering

            // Remove the node from the adjacency list and update the indegrees of its neighbors
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it); // Add the neighbor to the queue if its indegree becomes 0
                }
            }
        }
         if (topo.size() == V) {
            return topo; // All courses can be finished without any cycles in the prerequisites
        } else {
            return {}; // There is a cycle in the prerequisites, so not all courses can be finished
        }

    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends