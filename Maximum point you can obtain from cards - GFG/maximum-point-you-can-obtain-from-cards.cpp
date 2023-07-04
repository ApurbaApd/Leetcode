//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long maxScore(vector<int> &cardPoints, int N, int k) {
        // code here
        long long res,sum=0;
        
        //first k card
        for(int i=0;i<k;i++){
            sum += cardPoints[i];
        }
        
        res = sum;
        
        int i=k-1,j=N-1;
        
        while(i>=0){
            sum = sum - cardPoints[i] + cardPoints[j];
            res=max(res,sum);
            i--;
            j--;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> cardPoints(N);
        for (int i = 0; i < N; i++) cin >> cardPoints[i];

        Solution obj;
        cout << obj.maxScore(cardPoints, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends