//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++



int dp[500][2000];

class Solution {
public:
    int solve(int i, vector<int> &nums, int rem, int k) {
        if (i >= nums.size()) {
            return 0;
        }
        if (dp[i][rem] != -1) {
            return dp[i][rem];
        }
        int ans;
        if (nums[i] > rem) {
            ans = (rem + 1) * (rem + 1) + solve(i + 1, nums, k - nums[i] - 1, k);
        } else {
            ans = min(solve(i + 1, nums, rem - nums[i] - 1, k),
                      (rem + 1) * (rem + 1) + solve(i + 1, nums, k - nums[i] - 1, k));
        }
        dp[i][rem] = ans;
        return dp[i][rem];
    }

    int solveWordWrap(vector<int> nums, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, k, k);
    }
};





//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends