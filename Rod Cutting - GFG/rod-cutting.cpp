//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  //DP-Tabulation
    int cutRod(int price[], int n) 
    {
        vector<int>dp(n+1,0);
        //Base case
        for(int i=0;i<=n;i++){
            dp[i] = price[0]*i;
        }
        
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<=n;j++){
                int nottake = dp[j];
                int take = 0;
                if(i<=j-1)
                take = price[i] + dp[j-i-1];
                dp[j] = max(take,nottake);
            }
        }
        
        return  dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends