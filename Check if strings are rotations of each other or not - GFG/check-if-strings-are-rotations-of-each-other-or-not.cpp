//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.size() != s2.size()){
            return 0;
        }
        queue<char>q1, q2;
        for(auto ch: s1){
            q1.push(ch);
        }
        for(auto ch: s2){
            q2.push(ch);
        }
        int n=s2.size();
        while(n--){
            char ch = q2.front();
            q2.pop();
            q2.push(ch);
            if(q1 == q2){
                return 1;
            }
        }
        return 0;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends