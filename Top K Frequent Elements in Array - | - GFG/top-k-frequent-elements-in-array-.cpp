//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
          int n=nums.size();
           unordered_map<int, int>mp;//(nums[i], freq)
           for(int i=0; i<n; i++){
               mp[nums[i]]++;//incresing freq
           }

           priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>minH;
            
            vector<int>v;
            //traversing the map
            for(auto it: mp){
                minH.push({it.second, it.first});
                if(minH.size() > k){
                    minH.pop();
                }
            }

            while(!minH.empty()){
                v.push_back(minH.top().second);
                minH.pop();
            }
            
            reverse(v.begin(), v.end());

            return v;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends