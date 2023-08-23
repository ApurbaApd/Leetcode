//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
private:
    bool check(int nrow, int ncol, int n, int m, int size, const string &word, const vector<vector<char>> &grid, int k) {
        return (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && k < size && word[k] == grid[nrow][ncol]);
    }

public:
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans;
        int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == word[0]) {
                    for (int dir = 0; dir < 8; dir++) {
                        int nrow = i + dx[dir];
                        int ncol = j + dy[dir];
                        int size = word.size();
                        int k = 1;

                        while (check(nrow, ncol, n, m, size, word, grid, k)) {
                            nrow += dx[dir];
                            ncol += dy[dir];
                            k++;
                        }
                        if (k == size) {
                            ans.push_back({i, j});
                            break;
                        }
                    }
                }
            }
        }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends