//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        vector<double>temp;
        
        int m=array1.size(),n=array2.size();
        
        int i=0,j=0,k=0;
        
        while(i<m && j<n){
            if(array1[i]<array2[j]){
                temp.push_back(array1[i]);
                k++;
                i++;
            }
            else{
                temp.push_back(array2[j]);
                k++;
                j++;
            }
        }
        //remaining elements from arr1
        while(i<m){
            temp.push_back(array1[i]);
            k++;
            i++;
        }
        //remaining elements from arr2
         while(j<n){
            temp.push_back(array2[j]);
            k++;
            j++;
        }
    
        int len = temp.size();
        
        if( len & 1 ){//odd number of elements
            return temp[(len)/2];
        }
        else{//for even number of elements
            return (temp[(len)/2]+temp[(len-1)/2])/2;
        }
    
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends