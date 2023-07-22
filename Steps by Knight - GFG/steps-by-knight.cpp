//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
    {   
        vector<vector<int>> vis(N,vector<int>(N,0));
        vector<vector<int>> steps(N,vector<int>(N,1e9));
        int a=KnightPos[0]-1;
        int b=KnightPos[1]-1;
        int c=TargetPos[0]-1;
        int d=TargetPos[1]-1;
        vis[a][b]=1;
        steps[a][b]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({0,{a,b}});
        while(q.empty()==false)
        {
            int r=q.top().second.first;
            int c1=q.top().second.second;
            int dis=q.top().first;
            q.pop();
            
            int dr[]={-2,-2,-1,-1,0,1,1,2,2};
            int dc[]={-1,1,-2,2,0,2,-2,1,-1};
            for(int i=0;i<9;i++)
            {
                    int nr=r+dr[i];
                    int nc=c1+dc[i];
                    if(nr>=0 && nr<N && nc>=0 && nc<N && vis[nr][nc]==0 && steps[nr][nc]>dis+1)
                    {
                        vis[nr][nc]=1;
                        steps[nr][nc]=dis+1;
                        q.push({dis+1,{nr,nc}});
                    }
                
            }
        }
        return steps[c][d];
       
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends