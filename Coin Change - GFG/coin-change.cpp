//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // using memoization
    long long int usingMemoizationHelper(int currIndex, int*coins, int amount, vector<vector<long long int>>&dp)
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
        long long int notTake=usingMemoizationHelper(currIndex-1, coins, amount, dp);

        long long int take=0;
        if(coins[currIndex] <= amount)
        {
            take=usingMemoizationHelper(currIndex, coins, amount-coins[currIndex], dp);
            // why not currIndex-1, because there are infinite supply of coins are there
        }

        return dp[currIndex][amount] = (notTake + take);

    }
    long long int usingMemoization(int currIndex, int*coins, int amount, int n)
    {
        // creating a dp array of size [n][amount+1]
        vector<vector<long long int>>dp(n, vector<long long int>(amount+1,-1));

        return usingMemoizationHelper(currIndex, coins, amount, dp);
    }
    
    // using recursion
    long long int usingRecursion(int currIndex, int*coins, int amount)
    {
        // base case
        if(currIndex==0)
        {
            return (amount % coins[0]==0);
        }

        // small calculation
        long long int notTake=usingRecursion(currIndex-1, coins, amount);

        long long int take=0;
        if(coins[currIndex] <= amount)
        {
            take=usingRecursion(currIndex, coins, amount-coins[currIndex]);
            // why not currIndex-1, because there are infinite supply of coins are there
        }

        return notTake + take;
    }
    long long int count(int coins[], int n, int amount) 
    {
        // code here.
        // return usingRecursion(n-1, coins, amount);
        return usingMemoization(n-1, coins, amount, n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends