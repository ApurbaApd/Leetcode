//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
       //   Using Hashing
       int hash[n+1]={0};
       
       int repeat=-1,missing=-1;
       
       //update hash array
       for(int i=0;i<n;i++){
           hash[arr[i]]++;
       }
       
       //iterate through the hash array
       for(int i=1;i<=n;i++){
           if(hash[i] == 2) repeat = i;
           else if(hash[i] == 0) missing = i;
           
           if(repeat != -1 && missing != -1){
               break;
           }
       }
       return {repeat,missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends