//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string x)
{
    // code here
     stack<char> S;
        
        for(char it : x)
        {
            if(it == '(' or it == '{' or it == '[')
            S.push(it);
            
            else
            {
                if(it == ')')
                {
                    if(S.empty() or S.top() != '(')
                    return false;
                }
                
                if(it == '}')
                {
                    if(S.empty() or S.top() != '{')
                    return false;
                }
                
                if(it == ']')
                {
                    if(S.empty() or S.top() != '[')
                    return false;
                }
                
                S.pop();
            }
        }
        
        return S.empty();
}