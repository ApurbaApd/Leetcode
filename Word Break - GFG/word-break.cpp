//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.length();
        vector<int>dp(n+1,0);
        map<string,int>mp;
        for(auto it:B)
        {
            mp[it]++;
        }
       
        for(int i=0;i<n;i++)
        {
            if(mp[A.substr(0,i+1)]>=1)
            {
                dp[i]=1;
            }
            else
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(dp[j]==1 && mp[A.substr(j+1,(i-j))]>=1)
                    {
                        dp[i]=1;
                        break;
                    }
                }
            }
           
        }
        return dp[n-1];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends