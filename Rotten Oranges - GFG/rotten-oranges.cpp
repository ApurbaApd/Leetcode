//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        // Will use BFS
        int n = grid.size();
        int m = grid[0].size();

        // Queue and Visited array
        // {{r, c}, t}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({ { i, j }, 0 }); // starting point
                    vis[i][j] = 2; // Marking the element
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }

        int minTime = 0;

        // [i-1,j], [i+1,j], [i,j-1], [i,j+1]
        int delrow[] = { -1, 0, 1, 0 };
        int delcol[] = { 0, 1, 0, -1 };

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            minTime = max(minTime, t);
            q.pop();

            // Visiting 4 neighbors
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.push({ { nrow, ncol }, t + 1 });
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // Check if there is any unrotten orange
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] != 2 && grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return minTime;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends