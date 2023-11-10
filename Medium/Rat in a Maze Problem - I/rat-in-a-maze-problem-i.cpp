//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string>ans;
    void f(int i,int j,string s,vector<vector<int>> &m, int n)
    {
        if(i<0 or i>=n or j<0 or j>=n or m[i][j]==0)
        return;
        
        if(i==n-1 and j==n-1)
        {
            ans.push_back(s);
            s="";
            return;
        }
        
        m[i][j]=0;
        f(i+1,j,s+'D',m,n);
        f(i-1,j,s+'U',m,n);
        f(i,j-1,s+'L',m,n);
        f(i,j+1,s+'R',m,n);
        m[i][j]=1;
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        if(m[0][0]==0 or m[n-1][n-1]==0)
        return {};
        
        string s="";
        
        f(0,0,s,m,n);
        return ans;
        
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends