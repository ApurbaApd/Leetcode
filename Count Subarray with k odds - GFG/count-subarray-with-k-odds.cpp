//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    int atMost(int n, vector<int>& nums, int k) {
        
        int i=0, j=0, cntOdd = 0, ans = 0;

        while(j<n){
            if(nums[j] & 1){
                cntOdd++;
            }
            if(cntOdd > k){
                while(cntOdd > k && i<=j){
                    if(nums[i]&1){
                       cntOdd--;
                    }
                    i++;
                }
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
  public:
    int countSubarray(int n, vector<int>& nums, int k) {
        // Code here
        return atMost(n, nums, k) - atMost(n, nums, k-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends