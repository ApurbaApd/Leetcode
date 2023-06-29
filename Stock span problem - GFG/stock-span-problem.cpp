//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    { 
        //NGL INDEX
       // Your code here
        vector<int>v;
        stack<pair<int, int>>st;//(NGL, INDEX)
        
        for(int i=0; i<n; i++){
            
            if(st.empty()){
                v.push_back(-1);
            }
            
            else if(!st.empty() && st.top().first > price[i]){
                v.push_back(st.top().second);
            }
            
            else if(!st.empty() && st.top().first <= price[i]){
                while(!st.empty() && st.top().first <= price[i]){
                    st.pop();
                }
                
                if(st.empty()){
                    v.push_back(-1);
                }
                else{
                    v.push_back(st.top().second);
                }
            }
            
            st.push({price[i], i});
        }
        
        //get the index
        for(int i=0; i<v.size(); i++){
            v[i] = i - v[i];
        }
        
        return v;
    }
};



//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends