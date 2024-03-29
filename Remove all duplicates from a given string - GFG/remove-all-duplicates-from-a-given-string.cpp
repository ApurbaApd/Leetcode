//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    unordered_set<char>st;
	    string ans = "";
	    for(auto ch: str){
	        if(st.find(ch) == st.end()){
	           st.insert(ch);
    	        ans += ch;
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
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends