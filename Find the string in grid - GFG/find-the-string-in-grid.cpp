//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans;
        int dx[8] = {-1, -1, 0 , 1, 1, 1,0, -1};
        int dy[8] = {0 , 1, 1, 1, 0, -1, -1,-1};
        
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == word[0]){
                     for(int it = 0; it<8; it++){
                         int nrow = i + dx[it];
                         int ncol = j + dy[it];
                         int s = word.size();
                         int k = 1;
                         
                         while(nrow>=0 && nrow<n && ncol>=0 && ncol<m
                               && k<s && word[k] == grid[nrow][ncol])
                               {
                                   nrow += dx[it];
                                   ncol += dy[it];
                                   k++;
                               }
                        if(k == s)
                        {
                            ans.push_back({i,j});
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