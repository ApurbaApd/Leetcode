//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Node {
public:
    unordered_map<char, Node*> children;
    vector<int> indexes;
};

class Solution {
public:
    Node* root = new Node();

    void insert(string &str, int index) {
        Node* curr = root;
        for (auto ch : str) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new Node();
            }
            curr = curr->children[ch];
            curr->indexes.push_back(index);
        }
    }

    vector<int> search(string &str) {
        Node* curr = root;
        for (auto ch : str) {
            if (curr->children.find(ch) == curr->children.end()) {
                return {};
            }
            curr = curr->children[ch];
        }
        return curr->indexes;
    }

    vector<vector<string>> displayContacts(int n, string contact[], string str) {
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++) {
            insert(contact[i], i);
        }
        string s = "";
        for (char ch : str) {
            s += ch;
            vector<int> matches = search(s);
            if (matches.empty()) {
                ans.push_back({"0"});
            } else {
                set<string> uniqueContacts;
                for (int index : matches) {
                    uniqueContacts.insert(contact[index]);
                }
                vector<string> temp(uniqueContacts.begin(), uniqueContacts.end());
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends