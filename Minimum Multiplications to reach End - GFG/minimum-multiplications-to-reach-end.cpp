//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int MOD=100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        queue<int> q;
        q.push(start);
        
        vector<int> dist(MOD, INT_MAX);
        
        dist[start]=0;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            for(int i=0; i<arr.size();++i){
                int x = (arr[i] * num)%MOD;
                if(dist[x] > dist[num]+1){
                    dist[x] = dist[num]+1;
                    q.push(x);
                    if(x==end) return dist[x];
                }
                
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends