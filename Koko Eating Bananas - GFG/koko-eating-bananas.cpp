//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
private:
    int func(const vector<int>& piles, int hourly, int N) {
        int totalHours = 0;
        for (int i = 0; i < N; i++) {
            //static_cast<double>, converts int to double
            totalHours += ceil(static_cast<double>(piles[i]) / hourly);
        }
        
        return totalHours;
    }

public:
    int Solve(int N, vector<int>& piles, int H) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int totalHours = func(piles, mid, N);
            
            if (totalHours <= H) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends