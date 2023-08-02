//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string &s,int idx,int k,string &ans){
        ans=max(ans,s);
        if(k==0 || idx>=s.length())
            return;
        for(int j=idx+1;j<s.length();j++){
            if(s[j]>s[idx]){
                swap(s[idx],s[j]);
                solve(s,idx+1,k-1,ans);
                swap(s[idx],s[j]);
            }
        }
        solve(s,idx+1,k,ans);
    }
    string findMaximumNum(string s, int k){
        // code here
        string ans=s;
        solve(s,0,k,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends