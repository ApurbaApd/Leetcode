//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    int knapSack(int N, int W, int val[], int wt[]) {
        int dp[N][W + 1];
        
        // Base case
        for (int i = 0; i <= W; i++) {
            dp[0][i] = (i / wt[0]) * val[0];
        }
        
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= W; j++) {
                int notTake = dp[i - 1][j];
                int take = (wt[i] <= j) ? dp[i][j - wt[i]] + val[i] : INT_MIN;
                dp[i][j] = max(take, notTake);
            }
        }
        
        return dp[N - 1][W];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends