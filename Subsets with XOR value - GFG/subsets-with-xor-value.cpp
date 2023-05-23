//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
   int subsetXOR(vector<int>& arr, int N, int K) {
    int count = 0;
    unordered_map<int, int> xorCount;

    xorCount[0] = 1; // Initialize with empty subset

    for (int i = 0; i < N; i++) {
        unordered_map<int, int> newCount(xorCount);
        
        for (auto& kvp : xorCount) {
            int subsetXOR = kvp.first;
            int frequency = kvp.second;
            int newSubsetXOR = subsetXOR ^ arr[i];
            
            newCount[newSubsetXOR] += frequency;
        }
        
        xorCount = newCount;
    }

    count = xorCount[K]; // Number of subsets with XOR as K

    return count;
}

    
    
    
    // int subsetXOR(vector<int> arr, int N, int K) {
    //     // code here
    //     int xr = 0;
    //     map<int,int>mpp;
    //     mpp[xr]++;//{0,1}
    //     int cnt=0;
    //     for(int i=0;i<N;i++){
    //         xr = xr ^ arr[i];
    //         int x = xr ^ K;
    //         cnt += mpp[x];
    //         mpp[xr]++;
            
    //     }
    //     return cnt;
        
        
    // }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends