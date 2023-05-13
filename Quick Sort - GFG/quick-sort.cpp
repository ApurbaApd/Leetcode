//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low < high){
            int PI = partition(arr, low, high);//Tells Partion Index
            quickSort(arr, low, PI-1);//Sort the elements on the left side of Partition index
            quickSort(arr, PI+1, high);//Sort the elements on the right side of Partition index
        }
    }
    
    public:
    int partition (int arr[], int low, int high)//Step-1:Find the partition index and Place the pivot in it's correct position
    {
       // Your code here
       int pivot = arr[low];
       int i=low,j=high;
       while(i<j){
           while(arr[i]<=pivot && i<=high-1){
               i++;
           }
           while(arr[j]>pivot && j>=low+1){
               j--;
           }
           if(i<j) swap(arr[i],arr[j]);
       }
       swap(arr[low],arr[j]);
       return j;
       
       
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends