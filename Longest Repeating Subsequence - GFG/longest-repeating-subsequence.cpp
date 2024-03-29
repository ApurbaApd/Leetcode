//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
	    int dp[1001][1001];
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size();
		    memset(dp, 0, sizeof(dp));
		    string x=str;
		    string y=str;
		    
		    for(int i=1; i<n+1; i++){
		        for(int j=1; j<n+1; j++){
		            if(x[i-1] == y[j-1] && i!=j){
		                dp[i][j] = 1 + dp[i-1][j-1];
		            }
		            else{
		                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		            }
		        }
		    }
		    return dp[n][n];
		    
		}

};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends