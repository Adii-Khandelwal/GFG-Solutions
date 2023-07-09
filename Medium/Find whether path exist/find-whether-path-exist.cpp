//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
     bool dfs(int x, int y , vector<vector<int>>& grid, vector<vector<int>>& visited, int n, int m )
    {
        
        if(x<0 || x==n || y<0 || y==m || grid[x][y]==0 || visited[x][y])
        return false;
        
        if(grid[x][y]==2)
        return true;
        
        visited[x][y]=1;
        bool op1= dfs(x,y-1,grid,visited,n,m);
        bool op2= dfs(x-1,y,grid,visited,n,m);
        bool op3= dfs(x,y+1,grid,visited,n,m);
        bool op4= dfs(x+1,y,grid,visited,n,m);
        
        return op1 || op2 || op3 || op4;
    }
    
    
    
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                  return  dfs(i,j,grid,vis,n,m);
                 
                }
                
            }
        }
    f:
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends