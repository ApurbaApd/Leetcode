//{ Driver Code Starts
// Initial Template for C++

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
    private:
    bool isValid(int newr,int newc, int n){
        return newr >=0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        //step-1- connecting components
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 0) continue;
                //4-direction
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, -1, 0, 1};

                for(int ind=0;ind<4;ind++){
                    //Adjacent nodes
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if(isValid(newr, newc, n) && grid[newr][newc]){
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }

                }
            }
        }
        //step-2
        int maxi = 0;
        //Try to convert every 0 to 1 after checking condition
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col] == 1) continue;
                //4-direction
                int dr[] = {-1, 0, +1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int>components;
                for(int ind=0;ind<4;ind++){
                    //Adjacent nodes
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if(isValid(newr, newc, n)){
                      if(grid[newr][newc] == 1){
                          //insert parent of the node in set
                          components.insert(ds.findUltimateParent(newr * n + newc));
                      }
                    }
                }
                int totalSize = 0;
                for(auto it:components){
                    totalSize += ds.size[it];
                }
                maxi = max(maxi, totalSize +1);

            }
        }

        for(int cellNo = 0; cellNo < n * n; cellNo++){
            maxi = max(maxi, ds.size[ds.findUltimateParent(cellNo)]);
        }
        return maxi;
    }
};




























//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends