//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n, 1);
        vector<vector<int>> subseq(n, vector<int>());

        // Initialize the subsequence with each element as a starting point
        for (int i = 0; i < n; i++) {
            subseq[i].push_back(arr[i]);
        }

        int maxLen = 1;
        int maxIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[prev] < arr[i] && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    subseq[i] = subseq[prev]; // Extend the subsequence
                    subseq[i].push_back(arr[i]);

                    // Sort the extended subsequence lexicographically
                    sort(subseq[i].begin(), subseq[i].end());
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        return subseq[maxIdx];
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends