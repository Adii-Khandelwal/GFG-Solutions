//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        int row=i;
        int col=j;
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        while(!q.empty())
    {   row = q.front().first;
        col = q.front().second;
        q.pop();
        int delr[]={0,-1,-1,-1,0,1,1,1};
        int delc[]={-1,-1,0,1,1,1,0,-1};
        
        for(int i=0;i<8;i++)
        {
            int newr=row+delr[i];
            int newc=col+delc[i];
            
            if(newr>=0 and newr<n and newc>=0 and newc<m and grid[newr][newc]=='1' and vis[newr][newc]==0)
            {
                vis[newr][newc] = 1;
                q.push({newr,newc});
                
            }
        }
    }   
    }
  
  
  
  
  
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int island=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] and grid[i][j]=='1')
                {
                    island++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return island;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends