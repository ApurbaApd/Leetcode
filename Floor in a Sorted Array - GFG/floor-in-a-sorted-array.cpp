//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    // Function to find floor of x
    int findFloor(vector<long long>& v, long long n, long long x) {
        // Applying lower_bound on the vector
        auto it = lower_bound(v.begin(), v.end(), x);

        // If the element is present in the vector
        if (it != v.end() && *it == x) {
            return it - v.begin();
        }

        // If the element is not present, return the index of the element just smaller than x
        if (it != v.begin()) {
            return --it - v.begin();
        }

        // If no element is smaller than or equal to x
        return -1;
    }
};



//{ Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends