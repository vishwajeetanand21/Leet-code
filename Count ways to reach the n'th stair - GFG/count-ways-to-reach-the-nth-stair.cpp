//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    long long mod = 1e9+7;
    
    // using variables
    int usingVariables(int n)
    {
        // base case
        if(n<=1)
        {
            return n;
        }
        
        int a=0;
        int b=1;
        int c;
        
        for(int i=2;i<=n;i++)
        {
            c=(a%mod + b%mod)%mod;
            
            a=b;
            b=c;
        }
        
        return c%mod;
    }
    
    // using tabulation
    int usingTabulation(int n)
    {
        vector<int>dp(n+1);
        
        // base case
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]%mod + dp[i-2]%mod;
        }
        return dp[n]%mod;
    }
    
    // using memoization
    int usingMemoizationHelper(int n, vector<int>&dp)
    {
        // base case
        if(n<=1)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        dp[n]=usingMemoizationHelper(n-1,dp)%mod + usingMemoizationHelper(n-2,dp)%mod;
        
        return dp[n]%mod;
    }
    int usingMemoization(int n)
    {
        vector<int>dp(n+1,-1);
        return usingMemoizationHelper(n,dp);
    }
    
    // using recursion
    int usingRecursion(int n)
    {
        if(n==0||n==1)
        {
            return n;
        }
        return usingRecursion(n-1)+usingRecursion(n-2);
    }
    
    int countWays(int n)
    {
        // your code here
        // return usingRecursion(n+1);
        // return usingMemoization(n+1);
        // return usingTabulation(n+1);
        return usingVariables(n+1);
    }
};




//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends