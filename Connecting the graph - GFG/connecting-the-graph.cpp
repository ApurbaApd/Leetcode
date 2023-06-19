//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

//Disjoint set Data Structure
//Either use Union by Size or Union by Rank
//TC-O(4*alfha)
class DisjointSet{ 
  public:
    vector<int>rank, parent,size;
  	//n->no of nodes
  	DisjointSet(int n){
           rank.resize(n+1, 0);
           parent.resize(n+1);
           size.resize(n+1);
           for(int i=0;i<n;i++){
           	     parent[i] = i;
           	     size[i] = 1;
           }
  	}

  	int findUltimateParent(int node){
  		 //path compression
          if(node == parent[node])
          	return node;
          return parent[node] = findUltimateParent(parent[node]);
  	}

     // connect u and v; u->v
  	void unionByRank(int u, int v){
         int ulp_u = findUltimateParent(u);
         int ulp_v = findUltimateParent(v);

         if(ulp_u == ulp_v) return;

         if(rank[ulp_u] < rank[ulp_v]){
                 parent[ulp_u] = ulp_v;
         }
         else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
         }
         else{
         	parent[ulp_v] = ulp_u;
         	rank[ulp_u]++;
        }
  	}

  	void unionBySize(int u, int v){
         int ulp_u = findUltimateParent(u);
         int ulp_v = findUltimateParent(v);
         if(ulp_u == ulp_v) return;

         if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }


};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        //Disjoint ds will take care if it's o-based or 1-based
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it:edge){
            int u = it[0];
            int v = it[1];
            if(ds.findUltimateParent(u) == ds.findUltimateParent(v)){
                cntExtras++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        int cntCompo = 0;//No of connected components
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){//if node itself parent
                cntCompo++;
            }
        }
        int ans = cntCompo-1;
        if(cntExtras >= ans) return ans;
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends