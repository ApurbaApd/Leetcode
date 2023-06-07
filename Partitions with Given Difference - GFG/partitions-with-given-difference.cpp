//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends