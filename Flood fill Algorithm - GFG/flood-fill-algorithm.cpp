//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int initialColor) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        // Neighbors
        for (int i = 0; i < 4; i++) {
            int neighRow = row + delRow[i];
            int neighCol = col + delCol[i];
            if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m &&
                image[neighRow][neighCol] == initialColor && ans[neighRow][neighCol] != newColor) {
                dfs(neighRow, neighCol, ans, image, newColor, delRow, delCol, initialColor);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int initialColor = image[sr][sc];
        // Copy the 2D array
        vector<vector<int>> ans = image;
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(sr, sc, ans, image, newColor, delRow, delCol, initialColor);
        return ans;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends