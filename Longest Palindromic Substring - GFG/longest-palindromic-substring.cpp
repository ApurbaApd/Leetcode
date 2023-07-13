//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isPalindrome(const string& str) {
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    return (reversed == str);
}

string longestPalindrome(const string& str) {
    string longest = "";

    for (int i = 0; i < str.length(); i++) {
        string substring = "";

        for (int j = i; j < str.length(); j++) {
            substring += str[j];

            if (isPalindrome(substring)) {
                if (substring.length() > longest.length()) {
                    longest = substring;
                }
            }
        }
    }

    return longest;
}
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends