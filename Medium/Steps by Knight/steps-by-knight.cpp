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
	    // Code here
	    queue<pair<pair<int,int>,int>> q;
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    vector<vector<int> >vis(N+1,vector<int>(N+1,0));
	    int tm=INT_MAX;
	    while(!q.empty())
	    {
	        auto it=q.front();
	        int row=it.first.first;
	        int col=it.first.second;
	        int t=it.second;
	        vis[row][col]=1;
	        q.pop();
	        if(row==TargetPos[0] and col==TargetPos[1])
	        tm=min(t,tm);
	        int delr[]={-1,-2,-2,-1,1,2,2,1};
	        int delc[]={-2,-1,1,2,2,1,-1,-2};
	        for(int i=0;i<8;i++)
	        {
	            int r=row+delr[i];
	            int c=col+delc[i];
	            
	             if(r >= 1 && r<=N && c>=1 && c <=N && vis[r][c] == 0) {
                    vis[r][c] = 1;
                    q.push({{r, c}, t +1});
	        }
	        
	    }
	    }
	    if(vis[TargetPos[0]][TargetPos[1]] == 0) return -1;
	    return tm;
	    
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