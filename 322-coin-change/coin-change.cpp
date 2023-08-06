class Solution {
public:
    // using memoization
    int usingMemoizationHelper(int currIndex, vector<int>&coins, int amount, vector<vector<int>>&dp)
    {
        // base case
        if(currIndex==0)
        {
            // if the amount is 12 and coin denomination is 4=> then we can take 12/4=3 coins of 4 
            if(amount % coins[0]==0) 
            {
                return amount/coins[0];
            }
            else
            {
                // return -1;

                return 1e9; 
                // why not INT_MAX, because if any function will return INT_MAX then we will add 1 to it
                // it will overflow the variable, so it's better to use 1e9 instead of INT_MAX
            }
        }

        // now check the dp array
        if(dp[currIndex][amount] != -1)
        {
            return dp[currIndex][amount];
        }        

        // now write the same as the recursion

        // small calculation
        
        // not take this denomination
        int notTake=0 + usingMemoizationHelper(currIndex-1, coins, amount, dp);

        int take=INT_MAX;
        //We have to find the minimum coins so it's better to initialize the variable with a high value
        
        if(coins[currIndex] <= amount) // we can only take the coin if it's value will be less than target amount
        {
            take = 1 + usingMemoizationHelper(currIndex, coins, amount-coins[currIndex], dp);
            // IMPORTANT: Here we are not moving currIndex-1, because there are infinite supply of coins
            // we can take the coin multiple times, thus reducing the total amount
        }

        return dp[currIndex][amount] = min(take, notTake);        
    }
    int usingMemoization(int currIndex, vector<int>&coins, int amount, int n)
    {
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));

        return usingMemoizationHelper(currIndex, coins, amount, dp);
    }

    // using recursion
    int usingRecursion(int currIndex, vector<int>&coins, int amount)
    {
        // base case
        if(currIndex==0)
        {
            // if the amount is 12 and coin denomination is 4=> then we can take 12/4=3 coins of 4 
            if(amount % coins[0]==0) 
            {
                return amount/coins[0];
            }
            else
            {
                // return -1;

                return 1e9; 
                // why not INT_MAX, because if any function will return INT_MAX then we will add 1 to it
                // it will overflow the variable, so it's better to use 1e9 instead of INT_MAX
            }
        }

        // small calculation
        
        // not take this denomination
        int notTake=0 + usingRecursion(currIndex-1, coins, amount);

        int take=INT_MAX;
        //We have to find the minimum coins so it's better to initialize the variable with a high value
        
        if(coins[currIndex] <= amount) // we can only take the coin if it's value will be less than target amount
        {
            take = 1 + usingRecursion(currIndex, coins, amount-coins[currIndex]);
            // IMPORTANT: Here we are not moving currIndex-1, because there are infinite supply of coins
            // we can take the coin multiple times, thus reducing the total amount
        }

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) 
    {
        int n=coins.size();

        // int ans = usingRecursion(n-1, coins, amount);  
        int ans=usingMemoization(n-1, coins, amount, n); 

        return (ans>=1e9) ? -1 : ans;
    }
};