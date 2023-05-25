//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N) {
        // Create a temporary array for merging
        long long* temp = new long long[N];
        return mergeSort(arr, temp, 0, N - 1);
    }

private:
    long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
        long long i = left;    // Index for left subarray
        long long j = mid + 1; // Index for right subarray
        long long k = left;    // Index for merged subarray
        long long inversionCount = 0;

        // Merge the two subarrays while counting inversions
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inversionCount += (mid - i + 1); // Count inversions
            }
        }

        // Copy the remaining elements of left subarray (if any)
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy the remaining elements of right subarray (if any)
        while (j <= right) {
            temp[k++] = arr[j++];
        }

        // Copy the merged elements back to the original array
        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }

        return inversionCount;
    }

    long long int mergeSort(long long arr[], long long temp[], long long left, long long right) {
        long long inversionCount = 0;

        if (left < right) {
            long long mid = (left + right) / 2;

            // Recursively count inversions in the left and right subarrays
            inversionCount += mergeSort(arr, temp, left, mid);
            inversionCount += mergeSort(arr, temp, mid + 1, right);

            // Merge the two sorted subarrays and count inversions
            inversionCount += merge(arr, temp, left, mid, right);
        }

        return inversionCount;
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