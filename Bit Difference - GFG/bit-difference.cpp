//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countBits(int N, long long int A[]) {
        const int mod = 1e9 + 7;
        long long cnt = 0;

        for(int i=32; i>=0; i--) {
           long long ones = 0, zeros = 0;
            for(int j=0; j<N; j++) {
                
                if((A[j]>>i)&1) ones++;
                else 
                  zeros++;
            }

            cnt += (2*(ones*zeros));

        }
        return (int)(cnt%mod);

    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        long long int A[N];
        for(int i = 0;i < N; i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.countBits(N, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends