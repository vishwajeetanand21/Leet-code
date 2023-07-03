class Solution {
public:
    int usingVariables(int n)
    {
        if(n<=1)
        {
            return n;
        }

        int a=0, b=1, c;
        for(int i=2;i<=n;i++)
        {
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }

    int usingTabulationHelper(int dp[], int n)
    {
        dp[0]=0;
        dp[1]=1;

        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int usingTabulation(int n)
    {
        if(n<=1)
        {
            return n;
        }

        int dp[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=-1;
        }

        return usingTabulationHelper(dp,n);
    }

    int usingMemoizationHelper(int dp[], int n)
    {
        if(n<=1)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return dp[n]=usingMemoizationHelper(dp, n-1) + usingMemoizationHelper(dp,n-2);
    }
    int usingMemoization(int n)
    {
        int dp[n+1]; //make a dp array of size n+1 and store all the value in the dp array

        // initializa the dp array with -1
        for(int i=0;i<n+1;i++)
        {
            dp[i]=-1;
        }

        return usingMemoizationHelper(dp, n);
    } 

    int usingRecursion(int n)
    {
        if(n<=1)
        {
            return n;
        }
        return usingRecursion(n-1)+usingRecursion(n-2);
    }
    int fib(int n) 
    {
        // return usingRecursion(n);
        // return usingMemoization(n);
        // return usingTabulation(n);
        return usingVariables(n);
    }
};