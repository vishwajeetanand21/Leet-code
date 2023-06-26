//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int singleDigit(long long n)
    {
        if(n==0)
        {
            return 0;
        }
        
        int ans=n%9;
        if(ans==0)
        {
            return 9;
        }
        else
        {
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        int ans  = ob.singleDigit(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends