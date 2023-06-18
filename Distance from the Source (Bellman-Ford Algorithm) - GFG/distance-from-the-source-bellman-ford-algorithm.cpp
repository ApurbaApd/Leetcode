//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    /* Function to implement Bellman Ford
     * edges: vector of vectors which represents the graph
     * S: source vertex to start traversing graph with
     * V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Initialize distances array with a large value (infinity)
        vector<int> dist(V, 1e8);
        
        // Set the distance of the source vertex to 0
        dist[S] = 0;
        
        // Perform V-1 iterations
        for (int i = 0; i < V; i++) {
            // Traverse all edges
            for (auto it : edges) {
                int u = it[0]; // source vertex of the edge
                int v = it[1]; // destination vertex of the edge
                int wt = it[2]; // weight of the edge
                
                // Check if we reached the destination vertex 'v'
                // and if the current path has a smaller distance
                // than the previously known distance to 'v'
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    // Update the distance to 'v' with the new smaller distance
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Check for negative cycles by performing an additional iteration
        // If there is any vertex 'v' that can still be relaxed,
        // then there is a negative cycle in the graph
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                // If a negative cycle is found, return a vector with -1
                return {-1};
            }
        }
        
        // Return the distances from the source vertex to all other vertices
        return dist;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends