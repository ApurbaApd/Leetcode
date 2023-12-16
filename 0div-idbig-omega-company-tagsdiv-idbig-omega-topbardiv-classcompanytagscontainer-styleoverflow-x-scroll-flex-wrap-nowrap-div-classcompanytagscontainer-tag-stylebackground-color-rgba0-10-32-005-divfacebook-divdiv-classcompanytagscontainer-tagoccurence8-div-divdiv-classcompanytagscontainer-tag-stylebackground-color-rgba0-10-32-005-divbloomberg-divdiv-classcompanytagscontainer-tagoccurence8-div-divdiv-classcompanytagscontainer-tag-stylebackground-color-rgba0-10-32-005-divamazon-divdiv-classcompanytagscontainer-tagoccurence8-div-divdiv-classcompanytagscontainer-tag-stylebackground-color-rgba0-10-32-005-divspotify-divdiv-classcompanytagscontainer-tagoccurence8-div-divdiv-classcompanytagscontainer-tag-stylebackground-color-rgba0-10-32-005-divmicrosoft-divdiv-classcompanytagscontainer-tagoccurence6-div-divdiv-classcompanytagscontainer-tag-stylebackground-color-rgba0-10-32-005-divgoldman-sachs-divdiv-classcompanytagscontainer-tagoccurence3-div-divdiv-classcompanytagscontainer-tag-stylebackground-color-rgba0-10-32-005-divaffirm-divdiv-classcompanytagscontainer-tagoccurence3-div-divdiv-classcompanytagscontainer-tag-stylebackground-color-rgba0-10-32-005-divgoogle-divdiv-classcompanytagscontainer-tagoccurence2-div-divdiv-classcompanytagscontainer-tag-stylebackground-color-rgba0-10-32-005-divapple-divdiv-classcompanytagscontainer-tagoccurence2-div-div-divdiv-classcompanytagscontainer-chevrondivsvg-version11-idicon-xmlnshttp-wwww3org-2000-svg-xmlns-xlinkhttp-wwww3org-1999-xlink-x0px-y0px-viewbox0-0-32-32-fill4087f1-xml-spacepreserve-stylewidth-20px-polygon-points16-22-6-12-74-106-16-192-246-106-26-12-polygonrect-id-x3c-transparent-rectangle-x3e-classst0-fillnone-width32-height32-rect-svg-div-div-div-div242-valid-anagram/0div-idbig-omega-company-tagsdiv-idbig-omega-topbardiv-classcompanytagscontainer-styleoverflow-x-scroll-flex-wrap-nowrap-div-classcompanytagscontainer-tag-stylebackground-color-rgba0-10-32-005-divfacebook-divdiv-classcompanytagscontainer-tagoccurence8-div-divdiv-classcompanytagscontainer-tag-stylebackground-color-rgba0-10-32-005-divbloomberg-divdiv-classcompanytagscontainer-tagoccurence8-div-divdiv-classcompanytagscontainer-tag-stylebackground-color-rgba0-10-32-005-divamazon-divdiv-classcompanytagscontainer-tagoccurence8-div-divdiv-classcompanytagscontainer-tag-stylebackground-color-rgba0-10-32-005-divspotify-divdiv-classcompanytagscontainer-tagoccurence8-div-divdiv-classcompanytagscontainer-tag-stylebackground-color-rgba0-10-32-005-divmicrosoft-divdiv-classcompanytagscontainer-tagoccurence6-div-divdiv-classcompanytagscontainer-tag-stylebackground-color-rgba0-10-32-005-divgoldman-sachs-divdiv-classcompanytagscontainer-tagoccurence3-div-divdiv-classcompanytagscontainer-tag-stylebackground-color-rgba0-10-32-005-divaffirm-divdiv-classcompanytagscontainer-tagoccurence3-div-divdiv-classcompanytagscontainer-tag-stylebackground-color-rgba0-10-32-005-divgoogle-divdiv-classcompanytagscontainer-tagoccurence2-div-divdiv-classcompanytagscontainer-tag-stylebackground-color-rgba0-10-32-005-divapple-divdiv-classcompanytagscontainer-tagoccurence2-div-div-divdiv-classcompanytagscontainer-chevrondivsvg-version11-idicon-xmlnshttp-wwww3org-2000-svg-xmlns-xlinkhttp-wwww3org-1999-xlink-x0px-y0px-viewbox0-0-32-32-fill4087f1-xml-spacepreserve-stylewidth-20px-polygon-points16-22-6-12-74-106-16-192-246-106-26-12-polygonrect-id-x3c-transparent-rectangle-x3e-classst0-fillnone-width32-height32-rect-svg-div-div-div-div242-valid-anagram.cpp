class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.size(), m=t.size();
        int hash[26]={0};
        if(n != m) return 0;
        for(int i=0;i<n; i++){
            hash[s[i]-'a']++;
            hash[t[i]-'a']--;

        }
        for(int i=0; i<26; i++){
            if(hash[i] != 0){
                return 0;
            }
        }

        return 1;

      
    }
};