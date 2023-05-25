//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int Merge(vector<int>& nums, int low, int mid, int high) {
  // Initialize a variable to keep track of the total count of reverse pairs
  int total = 0;
  // Set the starting index for the second half of the subarray
  int j = mid + 1;

  // Iterate over the first half of the subarray
  for (int i = low; i <= mid; i++) {
    // Find the number of elements in the second half that form a reverse pair with nums[i]
    while (j <= high && nums[i] > 2LL * nums[j]) {
      j++;
    }
    // Increment the total count by the number of reverse pairs found
    total += (j - (mid + 1));
  }

  // Create a temporary vector to store the sorted subarray
  vector<int> t;
  // Set the starting indices for the two halves of the subarray
  int left = low, right = mid + 1;

  // Merge the two sorted halves of the subarray into the temporary vector
  while (left <= mid && right <= high) {
    // Compare the elements from the two halves and add the smaller element to the temporary vector
    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  // Add the remaining elements from the first half, if any
  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  // Add the remaining elements from the second half, if any
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  // Copy the sorted subarray from the temporary vector back to the original array
  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }

  // Return the total count of reverse pairs
  return total;
}

int MergeSort(vector<int>& nums, int low, int high) {
  // Base case: if the subarray has 0 or 1 elements, it is already sorted, so return 0
  if (low >= high) {
    return 0;
  }
  // Divide the subarray into two halves
  int mid = (low + high) / 2;

  // Recursively sort the two halves and count the reverse pairs
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);

  // Return the total count of reverse pairs
  return inv;
}
    
    
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        return MergeSort(arr, 0, arr.size() -1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends