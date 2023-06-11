//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here

        // Create a dynamic programming array to store the length of the longest increasing subsequence
        vector<int> dp(n, 1);

        // Create a 2D vector to store the actual subsequences
        vector<vector<int>> subseq(n, vector<int>());

        // Initialize the subsequence with each element as a starting point
        for (int i = 0; i < n; i++) {
            subseq[i].push_back(arr[i]);
        }

        int maxLen = 1; // Initialize the maximum length to 1
        int maxIdx = 0; // Initialize the index of the maximum length subsequence

        // Iterate over each element in the array
        for (int i = 0; i < n; i++) {
            // Check the elements before the current element
            for (int prev = 0; prev < i; prev++) {
                // If the previous element is smaller and the current subsequence length is smaller than the previous subsequence length plus 1
                if (arr[prev] < arr[i] && dp[i] < 1 + dp[prev]) {
                    // Update the current subsequence length
                    dp[i] = 1 + dp[prev];

                    // Extend the subsequence by copying the previous subsequence and adding the current element
                    subseq[i] = subseq[prev];
                    subseq[i].push_back(arr[i]);

                    // Sort the extended subsequence lexicographically
                    sort(subseq[i].begin(), subseq[i].end());
                }
            }

            // Check if the current subsequence length is greater than the maximum length found so far
            if (dp[i] > maxLen) {
                // Update the maximum length and the index of the maximum length subsequence
                maxLen = dp[i];
                maxIdx = i;
            }
        }

        // Return the longest increasing subsequence
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