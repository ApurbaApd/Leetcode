//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Recursion and Memoization
    int f(int ind,int n, vector<int>& arr, int k,  vector<int>&dp){
        if(ind == n) return 0;

        if(dp[ind] != -1) return dp[ind];

        int len=0;
        int maxiElement = INT_MIN;
        int largestSum = INT_MIN;

        for(int j=ind; j< min(ind+k, n);j++){
             len++;
             maxiElement=max(maxiElement, arr[j]);
             int sum = (len * maxiElement) + f(j+1, n, arr, k, dp);

             largestSum = max(largestSum, sum);
        }
        return dp[ind] = largestSum;
    }
    
    
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int>dp(n,-1);
        return f(0, n, arr, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends