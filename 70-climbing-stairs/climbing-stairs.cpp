class Solution {
public:
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
            c=a + b;
            
            a=b;
            b=c;
        }
        
        return c;
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


    int climbStairs(int n) 
    {
        // return usingRecursion(n+1);
        // return usingMemoization(n+1);
        // return usingTabulation(n+1);
        return usingVariables(n+1);
    }
};