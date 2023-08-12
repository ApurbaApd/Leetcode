//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int longestSubsequence(int n, int a[]) {
        // Create an empty vector to store the increasing subsequence elements
        vector<int> dp;
        
        // Iterate over each element in the input array
        for(int i = 0; i < n; i++) {
            // Perform binary search to find the position where a[i] can be inserted
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);
            
            // If the binary search returns dp.end(), a[i] is greater than all elements
            // in the dp array, so append a[i] to the end of the dp array
            if(it == dp.end()) {
                dp.push_back(a[i]);
            } 
            // If the binary search returns an iterator pointing to an element in dp,
            // replace that element with a[i] to maintain the sorted order
            else {
                *it = a[i];
            }
        }
        
        // Return the size of the dp array, which represents the length of the longest increasing subsequence
        return dp.size();
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends