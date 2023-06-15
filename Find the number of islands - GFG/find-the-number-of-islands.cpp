//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    void bfs(int i, int j,vector<vector<int>>&vis,vector<vector<char>>& grid ){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j] = 1;//starting element has been marked 1
        queue<pair<int, int>>q;
        
        //pshing starting elemet
        q.push({i, j});
        while(!q.empty()){//Till queue has element in it
            //First Take it and then delete it
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            ///Traverse the 8 neighbors and mark them if its a land
            for(int delRow = -1; delRow<= 1; delRow++){
                for(int delCol = -1;delCol<=1; delCol++){
                    int neighborRow = i + delRow;
                    int neighborCol = j + delCol;
                    if(neighborRow >=0 && neighborRow<n && neighborCol>=0 &&neighborCol<m &&
                       grid[neighborRow][neighborCol]=='1' && !vis[neighborRow][neighborCol]){
                        
                        vis[neighborRow][neighborCol] = 1;
                        q.push({neighborRow,neighborCol});
                    }
                }
            }
            
            
        }
    }
    
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();//row number
        int m=grid[0].size();//col number
        
        //replica of grid to see if the element is visited or not
        vector<vector<int>>vis(n, vector<int>(m, 0));//n x m
        
        int cnt=0;// To see how many times we call bfs and that will be our answer
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends