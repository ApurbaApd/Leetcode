//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findKRotation(int arr[], int n) {
        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check if the middle element is greater than the next element
            if (arr[mid] > arr[mid + 1])
                return mid + 1;

            // Check if the middle element is greater than the last element
            if (arr[mid] > arr[high])
                low = mid + 1;
            else
                high = mid;
        }

        // If the loop finishes, low will be the number of right rotations (K)
        return low;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends