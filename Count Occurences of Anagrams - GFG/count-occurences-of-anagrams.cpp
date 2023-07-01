//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution{
public:
    int search(string pat, string txt) {
        
       int count = 0;
       unordered_map<char, int>mp1;//for pat (letter, freq)
       unordered_map<char, int>mp2;//for current window
        
        int n1=pat.length();
        int n2=txt.length();
        
        for(int i=0;i<n1;i++){
            mp1[pat[i]]++;
        }
        
        int i=0, j=0;
        
        while(j<n1){
                mp2[txt[j]]++;
                j++;
            }
            if(mp1==mp2){
                count++;
            }
            
            while(j<n2){
            if(mp2[txt[i]]==1){
                mp2.erase(txt[i]);
            }
            else{
                mp2[txt[i]]--;
            }
            mp2[txt[j]]++;
            i++;
            j++;
            
            if(mp1==mp2){
                count++;
            }
        }
        return count;
   }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends