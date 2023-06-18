//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        //{diff,{row, col}}
        //Declare priority queue
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>,
           greater<pair<int, pair<int, int>>>> pq;
        
        int n=heights.size();
        int m=heights[0].size();
        
        //dist matrix
        vector<vector<int>>dist(n, vector<int>(m, 1e9));
        
         //Adjacent nodes row and col
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        //Starting point
        dist[0][0] = 0;
        pq.push({0, {0,0}});//push starting point {dist,{row,col}}
        
        while(!pq.empty()){
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            
            if(row == n-1 && col == m-1) return diff;
            
            //4-direction, 
            //row-1, col
            //row, col+1
            //row+1, col
            //row, col-1
            
           for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col+delcol[i];
                
                //Check for validity of the newrow and newcol
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m){
                     int newEffort = max( abs(heights[row][col] - heights[nrow][ncol]), diff);
                     if(newEffort < dist[nrow][ncol]){
                         dist[nrow][ncol] = newEffort;
                         pq.push({newEffort, {nrow, ncol}});
                     }
               }
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
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends