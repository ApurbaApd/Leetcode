//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>>&vis,vector<vector<int>>& grid,vector<pair<int, int>>&v, int row0, int col0){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        v.push_back({row-row0, col-col0});
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for(int k=0; k<4; k++){
            int nRow = row + dx[k];
            int nCol = col + dy[k];
            if(nRow >=0 && nRow<n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1){
                vis[nRow][nCol]=1;
                dfs(nRow, nCol, vis,grid, v, row0, col0);
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>>st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    vector<pair<int, int>>v;
                    dfs(i, j, vis,grid, v, i, j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};




//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends