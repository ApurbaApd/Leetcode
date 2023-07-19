//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0; i<n; i++) sum += arr[i];
	    
	    /* SusetSum code */
	    //Table
	    int dp[n+1][sum+1];
	    //base case
        for(int i=0; i<n+1; i++) dp[i][0] = 1;
        for(int j=0; j<sum+1; j++) dp[0][j] = 0;
        
         for(int i=1; i<n+1; i++){
             for(int j=1; j<sum+1; j++){
                 if(arr[i-1] <= j){
                     dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                 }
                 else
                   dp[i][j] = dp[i-1][j];
             }
         }
         
         
         //This qusetion specific code
         int mini = INT_MAX;
         //last row's cells where 1 is there we will take into consideration,
         for(int j=0; j<sum+1; j++){
             if(dp[n][j] == 1){
                 mini = min(mini, abs(sum - 2 * j));
             }
         }
         
         return mini;

	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends