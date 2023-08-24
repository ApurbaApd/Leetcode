//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends


class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       if(s1=="0"|| s2=="0"){
           return "0";
       }
      //int res=0;
      int n1=s1.length();
      int n2=s2.length();
      int value=0,res=0;
      string s(n1+n2,'0');
      for(int i=n1-1;i>=0;i--){
          if(s1[i]!='-'){
              for(int j=n2-1;j>=0;j--){
                  if(s2[j]!='-'){
                    res=(s1[i]-'0')*(s2[j]-'0');
                    value=(s[i+j+1]-'0')+res;
                    s[i+j+1]=(value%10)+'0';
                    s[i+j]=((s[i+j]-'0')+value/10)+'0';
                  }
              }
          }
      }
      int t=0;
            if((s1[0]=='-' && s2[0]!='-')||(s2[0]=='-' && s1[0]!='-') ){
          t=1;
          while(s[t]=='0'){
              t++;
          }
          s.erase(1,t-1);
          s[0]='-';
          return s;
      }
      while(s[t]=='0'){
          t++;
      }
      s.erase(0,t);
      return s;
    
    }

};


//{ Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends