//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends



class Solution {
public:
      int mod = 1e9+7;
    int perfectSum(int arr[], int n, int sum) {
        // DP->Tabulation
        // Declare the Dp
        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

        // Base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        if (arr[0] <= sum){
             if(arr[0]==0) 
                dp[0][arr[0]] = 2;
            else 
                dp[0][arr[0]] = 1;
        
            
        }
            

        for (int i = 1; i < n; i++) {
            for (int s = 0; s <= sum; s++) {
                int notTake = dp[i - 1][s] % mod;
                int take = 0;
                if (arr[i] <= s) {
                    take = dp[i - 1][s - arr[i]] % mod;
                }
                dp[i][s] = (take + notTake); 
            }
        }
        return dp[n - 1][sum] % mod;
    }
};



//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends