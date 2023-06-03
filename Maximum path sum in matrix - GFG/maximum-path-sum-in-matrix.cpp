//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


using namespace std;

class Solution {
public:
    int maximumPath(int N, vector<vector<int>>& Matrix) {
        // Create dp matrix
        vector<vector<int>> dp(N, vector<int>(N, 0));

        // Base case: Copy values from the first row of the input matrix
        for (int j = 0; j < N; j++) {
            dp[0][j] = Matrix[0][j];
        }

        // Dynamic programming to calculate the maximum path
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < N; j++) {
                int st = Matrix[i][j] + dp[i - 1][j];
                int ld = Matrix[i][j] + ((j - 1 >= 0) ? dp[i - 1][j - 1] : 0);
                int rd = Matrix[i][j] + ((j + 1 < N) ? dp[i - 1][j + 1] : 0);

                dp[i][j] = max(st, max(ld, rd));
            }
        }

        // Find the maximum value in the last row of the dp matrix
        int maxi = *max_element(dp[N - 1].begin(), dp[N - 1].end());

        return maxi;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends