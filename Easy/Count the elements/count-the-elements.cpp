//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;
vector<long long> find(vector<long long> a,vector<long long> b,vector<long long> q);

int main() {
    
    int t;

    cin >> t;

    while(t--){
       
       int n;
       cin >> n;
       vector<long long> a;
       vector<long long> b;
       vector<long long> ans;
       int input;
       for(int i =0;i<n;i++){
           cin>> input;
           a.push_back(input);
          }
       for(int i =0;i<n;i++){
           cin >> input;
           b.push_back(input);
       }
       int qsz;
       cin >> qsz;
       vector<long long> q;    
       for(int i =0;i<qsz;i++)
        {
           cin >> input;
           q.push_back(input);
        }
        ans= find(a,b,q);
        for(int i =0;i<qsz;i++){
            cout<< ans[i] << endl;
      }
    }
    return 0;
}
// } Driver Code Ends


//User function Template for C++

vector<long long> find(vector<long long> a,vector<long long> b,vector<long long> q) {

vector<long long>ans;

int i=0;
int cnt=0;
while(i<q.size())
{
     cnt=0;
    int x=a[q[i]];
    for(long long i=0;i<b.size();i++)
    {
        if(b[i]<=x)
        cnt++;
    }
    ans.push_back(cnt);
    i++;
    
}
return ans;

}
