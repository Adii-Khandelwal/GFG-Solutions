//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
 void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int newColor, int delRow[], int delCol[],
     int iniColor) {
        // color with new color
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int i = 0;i<4;i++) {
            int nrow = row + delRow[i]; 
            int ncol = col + delCol[i]; 
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, delRow, delCol, iniColor); 
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1}; 
        dfs(sr, sc, ans, image, newColor, delRow, delCol, iniColor); 
        return ans; 
    }
};
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         // Code here 
//         // int iniclr=image[sr][sc];
//         // queue<pair<int,int>>q;
//         // int n=image.size();
//         // int m=image[0].size();
//         // q.push({sr,sc});
//         // vector<vector<int>>ans=image;
//         // int delr[]={-1,0,1,0};
//         // int delc[]={0,1,0,-1};

//         // while(!q.empty())
//         // {
//         //     auto it=q.front();
//         //     int row=it.first;
//         //     int col=it.second;
//         //     ans[row][col]=newColor;
//         //   q.pop();
            
//         //     for(int i=0;i<4;i++)
//         //     {
//         //         int nrow=row+delr[i];
//         //         int ncol=col+delc[i];
                
//         //          if(nrow>=0 and nrow<n and ncol >=0 and ncol<m and image[nrow][ncol]==iniclr and ans[nrow][ncol]!=newColor)
//         //         {
//         //             q.push({nrow,ncol});
                     
//         //         }
//         //     }
            
//         // }
//         // return ans;
//         
//     }
// };

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends