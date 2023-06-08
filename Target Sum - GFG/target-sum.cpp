//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  
   int countPartitions(int n, int d, vector<int>& arr) {
    const int MOD = 1000000007;
    long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);

   
    if ((totalSum-d) % 2 != 0 || d > totalSum) {
        return 0;
    }

    int targetSum = (totalSum - d) / 2;
    vector<int> dp(targetSum + 1, 0);
    dp[0] = 1;//BC

    for (int i = 0; i < n; i++) {
        for (int j = targetSum; j >= arr[i]; j--) {
            dp[j] = (dp[j] + dp[j - arr[i]]) % MOD;
        }
    }

    return dp[targetSum];
  
   }
  
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here.
        int n = A.size();
        
        return countPartitions(n,target, A);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends