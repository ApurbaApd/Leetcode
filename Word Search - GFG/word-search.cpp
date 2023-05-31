//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Define a 2D vector to keep track of visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Iterate through each cell on the board
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && dfs(board, word, visited, i, j, 0)) {
                    // If the first character of the word is found and DFS returns true
                    return true;
                }
            }
        }
        
        // The word does not exist on the board
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int index) {
        // Check if all characters of the word have been found
        if (index == word.length()) {
            return true;
        }
        
        int rows = board.size();
        int cols = board[0].size();
        
        // Check if the current cell is out of bounds or has been visited or does not match the word
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Recursively check the neighboring cells
        if (dfs(board, word, visited, i + 1, j, index + 1) ||
            dfs(board, word, visited, i - 1, j, index + 1) ||
            dfs(board, word, visited, i, j + 1, index + 1) ||
            dfs(board, word, visited, i, j - 1, index + 1)) {
            return true;
        }
        
        // Mark the current cell as unvisited (backtracking)
        visited[i][j] = false;
        
        return false;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends