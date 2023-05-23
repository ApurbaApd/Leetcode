//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
   public:
vector<vector<int>> fourSum(vector<int> &arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    set<vector<int>> st;
    
    for (int i = 0; i < n - 3; i++) {
        for (int j = i + 1; j < n - 2; j++) {
            int target = k - (arr[i] + arr[j]);
            int left = j + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = arr[left] + arr[right];
                
                if (sum < target) {
                    left++;
                } else if (sum > target) {
                    right--;
                } else {
                    st.insert({arr[i], arr[j], arr[left], arr[right]});
                    left++;
                    right--;
                }
            }
        }
    }
    
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}









   //BF//TLE,TC-O(N^4)
    // vector<vector<int>> fourSum(vector<int> &arr, int k) {
    //     int n = arr.size();
    //     sort(arr.begin(), arr.end());
    //     set<vector<int>> st;
        
    //     for (int i = 0; i < n - 3; i++) {
    //         for (int j = i + 1; j < n - 2; j++) {
    //             for (int m = j + 1; m < n - 1; m++) {
    //                 for (int l = m + 1; l < n; l++) {
    //                     long long sum = arr[i] + arr[j] + arr[m] + arr[l];
                        
    //                     if (sum == k) {
    //                         st.insert({ arr[i], arr[j], arr[m], arr[l] });
    //                     }
    //                 }
    //             }
    //         }
    //     }
        
    //     vector<vector<int>> ans(st.begin(), st.end());
    //     return ans;
    // }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends