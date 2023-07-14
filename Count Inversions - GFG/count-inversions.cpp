//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
 private:
    void merge(long long arr[], long long l, long long m, long long h,long long &ans)
    {
         vector<long long> temp;
         long long left=l,right=m+1;
         while(left<=m && right<=h){
             if(arr[left]<=arr[right]){
                 temp.push_back(arr[left]);
                 left++;
             }
             else{
                 temp.push_back(arr[right]);
                 right++;
                 ans+=(m-left+1);
             }
         }
         while(left<=m){
              temp.push_back(arr[left]);
                 left++;
         }
         while(right<=h){
               temp.push_back(arr[right]);
                 right++;
          }
          
        for(long long i = l; i<=h; i++){
            arr[i] = temp[i-l];
        }
    }
    void mergeSort(long long arr[], long long l, long long h,long long &ans)
    {
        if(l==h) return;
        long long m=(l+h)/2;
        mergeSort(arr,l,m,ans);
        mergeSort(arr,m+1,h,ans);
        merge(arr,l,m,h,ans);
    }
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans=0;
        mergeSort(arr,0,N-1,ans);
        return ans;
    }

};




//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends