//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        
       int cnt5 = 0, cnt10 = 0, cnt20 = 0;

       for(auto it: bills){
          // Customer paid 5$
           if(it == 5) cnt5++;

           // Customer paid 10$
           else if(it == 10) {
                if(cnt5 == 0) return false; // No 5$ bill available to give change
                cnt10++;
                cnt5--;
           }
           // Customer paid 20$
           else {
                if (cnt5 > 0 && cnt10 > 0) {
                    cnt5--;
                    cnt10--;
                }
                else if (cnt5 >= 3) {
                    cnt5 -= 3;
                }
                else {
                    return false;
                }
            }
       }
       return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends