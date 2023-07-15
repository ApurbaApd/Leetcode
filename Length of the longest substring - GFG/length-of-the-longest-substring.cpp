//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector<int> v(256,0);
        int j=0,n=s.size(),i=0;
        int mx=0;
        while(j<n){
            v[s[j]]++;
            
            if(v[s[j]]==1){  // If the count of s[j] is 1 (first occurrence)
                mx=max(mx,j-i+1);
                j++;  // move window forward
            }
            else{// If the count of s[j] is greater than 1 (repeated occurrence)
                while(v[s[j]]>1){
                    v[s[i]]--;// Decrement the count of character s[i] in the vector v
                    i++; // Move the left pointer forward
                }
                j++;
            }
        }
        return mx;
    }
};



//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends