//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  
  
    int shortestDistance(int N, int M, vector<vector<int>> grid, int X, int Y) {
         int ans=N*M;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>visited(N,vector<int>(M,0));
         int dir[5]={0,1,0,-1,0};
        visited[0][0]=1;
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int st=top.first;
            int x=top.second.first;
            int y=top.second.second;
            if(x==X && y==Y){
                ans=min(ans,st);
                continue;
            }
            for(int i=0;i<4;i++){
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(nx>=0 && ny>=0 && nx<N && ny<M && visited[nx][ny]==0 && grid[nx][ny]==1){
                    q.push({st+1,{nx,ny}});
                    visited[nx][ny]=1;
                }
            }
        }
        return ans==N*M?-1:ans;  
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends