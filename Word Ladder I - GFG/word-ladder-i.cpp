//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here//BFS
        queue<pair<string, int>>q;
        q.push({startWord, 1});
        //coppying the wordList to set
        unordered_set<string>st(wordList.begin(), wordList.end());
        st.erase(startWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == targetWord) return steps;
            
            //word->hat
            for(int i=0;i<word.size();i++){
                char original = word[i];//h
                for(char c ='a'; c <= 'z'; c++){
                    word[i] = c;//aat, bat, cat, dot........zot
                    if(st.find(word) != st.end()){//check if the changed word exist in set
                        //if exits
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                //if changed word does not exist in set then get back to original word
                word[i] = original;
            }
            
            
        }
        
        return 0;
        
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends