//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    int maxEqualSum(int N1, int N2, int N3, vector<int>& S1, vector<int>& S2, vector<int>& S3) {
        int sum1 = 0, sum2 = 0, sum3 = 0;  // Initialize sums of the stacks
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;  // Initialize pointers

        // Calculate initial sums of the stacks
        for (int i = 0; i < N1; i++)
            sum1 += S1[i];
        for (int i = 0; i < N2; i++)
            sum2 += S2[i];
        for (int i = 0; i < N3; i++)
            sum3 += S3[i];

        while (true) {
            // If sums of all three stacks are equal, return the sum
            if (sum1 == sum2 && sum2 == sum3)
                return sum1;

            // Find the stack with the maximum sum and remove its top element
            if (sum1 >= sum2 && sum1 >= sum3) {
                sum1 -= S1[ptr1];
                ptr1++;
            } else if (sum2 >= sum1 && sum2 >= sum3) {
                sum2 -= S2[ptr2];
                ptr2++;
            } else {
                sum3 -= S3[ptr3];
                ptr3++;
            }
        }
    }
};



//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends