class Solution {
public:
    // using memoization
    int usingMemoizationHelper(int currIndex, vector<int>&coins, int amount, vector<vector<int>>&dp)
    {
        // base case
        if(currIndex==0)
        {
            return (amount % coins[0]==0);
        }

        // now check for the dp array
        if(dp[currIndex][amount] != -1)
        {
            return dp[currIndex][amount];
        }

        // write the same thing as recursion
        
        // small calculation
        int notTake=usingMemoizationHelper(currIndex-1, coins, amount, dp);

        int take=0;
        if(coins[currIndex] <= amount)
        {
            take=usingMemoizationHelper(currIndex, coins, amount-coins[currIndex], dp);
            // why not currIndex-1, because there are infinite supply of coins are there
        }

        return dp[currIndex][amount] = (notTake + take);

    }
    int usingMemoization(int currIndex, vector<int>&coins, int amount, int n)
    {
        // creating a dp array of size [n][amount+1]
        vector<vector<int>>dp(n, vector<int>(amount+1,-1));

        return usingMemoizationHelper(currIndex, coins, amount, dp);
    }

    // using recursion
    int usingRecursion(int currIndex, vector<int>&coins, int amount)
    {
        // base case
        if(currIndex==0)
        {
            return (amount % coins[0]==0);
        }

        // small calculation
        int notTake=usingRecursion(currIndex-1, coins, amount);

        int take=0;
        if(coins[currIndex] <= amount)
        {
            take=usingRecursion(currIndex, coins, amount-coins[currIndex]);
            // why not currIndex-1, because there are infinite supply of coins are there
        }

        return notTake + take;
    }
    int change(int amount, vector<int>& coins) 
    {
        int n=coins.size();

        // return usingRecursion(n-1, coins, amount);
        return usingMemoization(n-1, coins, amount, n);

    }
};