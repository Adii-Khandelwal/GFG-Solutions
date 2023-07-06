//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        
        int n=grid.size();
        int m=grid[0].size();
       queue<pair<pair<int,int>,int>> q;
        
        
        vector<int> dist(n);
        int vis[n][m];
        int cntfrsh=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                   q.push({{i,j},0});
                   vis[i][j]=2;
                }
                else
                {
                    vis[i][j]=0;
                    if(grid[i][j]==1)
                    {
                        cntfrsh++;
                    }
                }
                
            }
        }
        int tm=0;
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        int cnt=0;
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            tm=max(t,tm);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=r+delr[i];
                int ncol=c+delc[i];
                
                if(nrow>=0 and nrow<n and ncol >=0 and ncol<m and grid[nrow][ncol]==1 and vis[nrow][ncol]==0)
                {
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
                
            }
        }
        if(cnt!=cntfrsh)
        {
            return -1;
        }
        return tm;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends