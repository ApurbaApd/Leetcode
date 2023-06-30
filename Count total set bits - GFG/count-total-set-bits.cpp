//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    // Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n) {
        int cnt = 0;
        int powerOfTwo = 1;
        
        while (powerOfTwo <= n) {
            int numSets = (n + 1) / (2 * powerOfTwo);  // Number of complete sets of 0s and 1s
            int numRemainder = (n + 1) % (2 * powerOfTwo); // Number of remaining bits
            
            cnt += numSets * powerOfTwo; // Count the set bits in complete sets
            cnt += max(0, numRemainder - powerOfTwo); // Count the remaining set bits
            
            powerOfTwo *= 2; // Move to the next power of 2
        }
        
        return cnt;
    }
};



//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends