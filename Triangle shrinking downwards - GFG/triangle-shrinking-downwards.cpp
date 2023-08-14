//{ Driver Code Starts
#include <bits/stdc++.h>
#include<string>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string triDownwards(string str) 
    {
        // code here
        int n=str.size();
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                // cout<<"*";
                ans.push_back('.');
            }
            for(int j=i;j<n;j++)
            {
                // cout<<str[j];
                ans.push_back(str[j]);
            }
            // cout<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin >> S;

        Solution ob;
        string ans=ob.triDownwards(S);
        
        for(int i=0 ; i<ans.length() ; i++)
        {
            cout<<ans[i];
            if((i+1)%S.length()==0)
                cout<<endl;
        }
        
    }
    return 0;
}
// } Driver Code Ends