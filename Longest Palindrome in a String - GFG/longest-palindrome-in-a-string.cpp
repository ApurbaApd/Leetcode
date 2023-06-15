//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int n = S.size();
        int anslen = 0;
        string ans = "";
        
        for(int i = 0; i<n; i++){
            //odd length
            int l = i, r=i;
            while(S[l] == S[r] && l>=0 && r<n){
                if(r-l+1 > anslen){
                    anslen = r-l+1;
                    ans = S.substr(l, anslen);
                }
                
                l--;
                r++;
            }
            //even length
            l = i, r=i+1;
            while(S[l] == S[r] && l>=0 && r<n){
                if(r-l+1 > anslen){
                    anslen = r-l+1;
                    ans = S.substr(l, anslen);
                }
                l--;
                r++;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends