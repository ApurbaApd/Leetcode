//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here//PRIM'S ALGORITHM
        //First we will create  the graph
        //Declare priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        //We need visited array
        vector<int>vis(V, 0);
        //As we only have to find sum of weights
        
        int sum = 0;
        //push the starting node
        pq.push({0, 0});//{weight, current node}
        while(!pq.empty()){
            int weight = pq.top().first;
            int curnode = pq.top().second;
            pq.pop();
            
            //if the node is already visited
            if(vis[curnode] == 1) continue;
            //when we add it to the mst
            vis[curnode] = 1;
            sum += weight;
            
            //Adjacent element
            for(auto it:adj[curnode]){
                int adjNode = it[0];
                int newWeight = it[1];
                
                if(!vis[adjNode]){
                    pq.push({newWeight,adjNode });
                }
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends