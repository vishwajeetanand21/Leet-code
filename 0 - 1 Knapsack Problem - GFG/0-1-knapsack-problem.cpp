//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    // using tabulation
    int usingTabulation(int bagWeight, int*itemWeight, int *itemValue, int n)
    {
        // creating a dp array of size [n][bagWeight+1]
        vector<vector<int>>dp(n, vector<int>(bagWeight+1, 0));
        
        // initialize the first element of dp array
        for(int w=itemWeight[0]; w<=bagWeight; w++)
        {
            dp[0][w]=itemValue[0];
        }
        
        // write the nested loops
        for(int index=1; index<n; index++)
        {
            for(int weight=0; weight<=bagWeight; weight++)
            {
                // now copy the same small calculation from the memoization step
                // and change the recursion to dp
                
                // not take this item
                int notTake=0 + dp[index-1][weight];
                
                // take this element
                int take=INT_MIN;
                if(itemWeight[index] <= weight)
                {
                    take=itemValue[index] + dp[index-1][ weight-itemWeight[index] ];
                }
                
                dp[index][weight] = max(take, notTake);
            }
        }
        
        return dp[n-1][bagWeight];
    }
    
    // using memoization
    int usingMemoizationHelper(int currIndex, int bagWeight, int*itemWeight, int *itemValue, vector<vector<int>>&dp)
    {
        // first check the base case
        if(currIndex==0) //when we reached the 0th index
        {
            if(itemWeight[0]<=bagWeight) //we can take the 0th index element only when it's weight is <= bagWeight
            {
                return itemValue[0]; // take this element
            }
            else //if the weight of 0th index element is > bagWeight, then don't take the element
            {
                return 0; //don't take this element
            }
        }
        
        // now check the dp array
        if(dp[currIndex][bagWeight] != -1)
        {
            return dp[currIndex][bagWeight];
        }
        
        // write the same thing as the recursion
        
        // not take this item
        int notTake=0 + usingMemoizationHelper(currIndex-1, bagWeight, itemWeight, itemValue, dp);
        
        // take this element
        int take=INT_MIN;
        if(itemWeight[currIndex] <= bagWeight)
        {
            take=itemValue[currIndex] + usingMemoizationHelper(currIndex-1, bagWeight-itemWeight[currIndex], itemWeight, itemValue, dp);
        }
        
        return dp[currIndex][bagWeight] = max(take, notTake);
    }
    int usingMemoization(int currIndex, int bagWeight, int*itemWeight, int itemValue[], int n)
    {
        // creating a dp array of size [n][weight+1]
        vector<vector<int>>dp(n, vector<int>(bagWeight+1, -1));
        
        return usingMemoizationHelper(currIndex, bagWeight, itemWeight, itemValue, dp);
    }
    
    
    
    // using recursion
    int usingRecursion(int currIndex, int bagWeight, int *itemWeight, int *itemValue)
    {
        // base condition
        if(currIndex==0) //when we reached the 0th index
        {
            if(itemWeight[0]<=bagWeight) //we can take the 0th index element only when it's weight is <= bagWeight
            {
                return itemValue[0]; // take this element
            }
            else //if the weight of 0th index element is > bagWeight, then don't take the element
            {
                return 0; //don't take this element
            }
        }
        
        // small calculation
        
        // not take the item
        int notTake=0 + usingRecursion(currIndex-1, bagWeight, itemWeight, itemValue);
        
        // take this element
        int take=INT_MIN;
        if(itemWeight[currIndex] <= bagWeight)
        {
            take=itemValue[currIndex] + usingRecursion(currIndex-1, bagWeight-itemWeight[currIndex], itemWeight, itemValue);
        }
        
        return max(take, notTake);
    }
    
    
    int knapSack(int bagWeight, int itemWeight[], int itemValue[], int n) 
    { 
        // Your code here
        // return usingRecursion(n-1, bagWeight, itemWeight, itemValue);
        // return usingMemoization(n-1, bagWeight, itemWeight, itemValue, n);
        return usingTabulation(bagWeight, itemWeight, itemValue, n);
        
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends