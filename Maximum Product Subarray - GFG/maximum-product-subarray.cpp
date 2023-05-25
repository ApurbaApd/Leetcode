//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long prefixPdt = 1, suffixPdt=1;
        long long maximum = INT_MIN;
        for(int i=0;i<n;i++){
            if(prefixPdt==0) prefixPdt=1;//if product turns 0 then restart
            if(suffixPdt==0) suffixPdt=1;
            
            prefixPdt = prefixPdt * arr[i];//start from 0 index
            suffixPdt = suffixPdt * arr[n-i-1];//start from last index

            maximum = max(maximum, max(prefixPdt, suffixPdt));

        }
        return maximum;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends