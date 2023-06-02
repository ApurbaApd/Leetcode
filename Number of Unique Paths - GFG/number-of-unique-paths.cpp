//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    //Tabulation
    int NumberOfPath(int a, int b)
    {
        //code here
        int dp[a][b];
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int up = 0,left =0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[a-1][b-1];
        
    }
};



// class Solution {
// public:
//   //Memoization
//     int f(int i, int j, vector<vector<int>>& dp) {
//         if (i == 0 && j == 0)
//             return 1;
        
//         if (i < 0 || j < 0)
//             return 0;
        
//         if (dp[i][j] != -1)
//             return dp[i][j];
        
//         int up = f(i - 1, j, dp);
//         int left = f(i, j - 1, dp);
        
//         return dp[i][j] = up + left;
//     }

//     int NumberOfPath(int a, int b) {
//         vector<vector<int>> dp(a, vector<int>(b, -1)); // Declaring a dp
//         return f(a - 1, b - 1, dp);
//     }
// };



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends