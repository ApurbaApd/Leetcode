//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
      // your code here
      unordered_map<char, int>mpp;
      int i=0, j=0, mx = INT_MIN;
      
      while(j < s.size()){
          
          mpp[s[j]]++;
          
          if(mpp.size() < k){
              j++;
          }
          
          else if(mpp.size() == k){
              mx = max(mx, j-i+1);
              j++;
          }
          
          else if(mpp.size() > k){
              while(mpp.size() > k){
                  mpp[s[i]]--;
                  if(mpp[s[i]] == 0){
                      mpp.erase(s[i]);
                  }
                  i++;
              }
              j++;
          }
      }
      return (mx != INT_MIN) ? mx : -1;
    
    
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends