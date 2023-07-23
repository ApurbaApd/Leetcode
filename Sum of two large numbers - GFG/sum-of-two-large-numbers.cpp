//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:
    string findSum(string X, string Y) {
        int i = X.size() - 1;
        int j = Y.size() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0)
                sum += (X[i] - '0');

            if (j >= 0)
                sum += (Y[j] - '0');

            result.push_back('0' + sum % 10);
            carry = sum / 10;

            i--;
            j--;
        }

        reverse(result.begin(), result.end());

        // Remove leading zeros
        int nonZeroIndex = 0;
        while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
            nonZeroIndex++;
        }
        
        if (nonZeroIndex == result.size()) // All digits were zeros
            return "0";

        return result.substr(nonZeroIndex);
    }
};



//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends