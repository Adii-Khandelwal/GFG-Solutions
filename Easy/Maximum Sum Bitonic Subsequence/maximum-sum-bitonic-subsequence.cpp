//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
int maxSumBS(int arr[] , int n );

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumBS(a,n)<<endl;
		
	}
}
// } Driver Code Ends


int maxSumBS(int arr[] , int n )
{
    int pref[n+1] = {0}, suff[n+1] = {0}, ans = 0;
    for(int i=1; i<=n; i++){
        pref[i] = arr[i-1];
        for(int j=i-1; j>=0; j--){
            if(arr[j-1] < arr[i-1])
                pref[i] = max(pref[i], arr[i-1]+pref[j]);
        }
    }
    for(int i=n; i>=1; i--){
        suff[i] = arr[i-1];
        for(int j=i+1; j<=n; j++){
            if(arr[i-1] > arr[j-1])
                suff[i] = max(suff[i], arr[i-1]+suff[j]);
        }
    }
    for(int i=1; i<=n; i++){
        ans = max({ans, pref[i], suff[i]});
        for(int j=i+1; j<=n; j++){
            if(arr[j-1] < arr[i-1])
                ans = max(ans, pref[i]+suff[j]);
        }
    }
    return ans;
    
}
