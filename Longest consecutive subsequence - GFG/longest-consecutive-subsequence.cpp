//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      if(N==0) return 0;
         //TC-O(N+NlogN),SC-O(1)
         //First sort the elements
         sort(arr,arr+N);//O(NlogN)
         int cnt=0,longest=1,lastSmaller=INT_MIN;
         for(int i=0;i<N;i++){//iterating the whole array//O(N)
             if(arr[i]-1 == lastSmaller){//if one smaller element than nums[i] exist in the array
                 cnt++;
                 lastSmaller=arr[i];
             }
             else if(arr[i] != lastSmaller){//starting a new sequence
                 cnt=1;
                 lastSmaller=arr[i];
             }
             longest=max(longest,cnt);
         }
         return longest;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends