//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int minManipulation (int n, string s1, string s2);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string s1; cin >> s1;
        string s2; cin >> s2;

        cout << minManipulation (n, s1, s2) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minManipulation (int N, string s, string t)
{
    // your code here
 int cnt=0;
        
        int alpha[26]={0};
        
        for(int i=0;i<s.size();i++)
        {
            alpha[s[i]-'a']++;
            alpha[t[i]-'a']--;
        }
        
        for(auto it:alpha)
        {
            if(it>0)
                cnt+=it;
                
        }
        
        return cnt;
      
    
}