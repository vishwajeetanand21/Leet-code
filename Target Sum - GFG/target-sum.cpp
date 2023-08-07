//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    // using memoization
    int usingMemoizationHelper(int currIndex, vector<int>&arr, int target, vector<vector<int>>&dp)
    {
       // base case
        if(currIndex==0)
        {
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target==arr[0])
                return 1;
            else    
                return 0;
        }

        // now check the dp array
        if(dp[currIndex][target] != -1)
        {
            return dp[currIndex][target];
        }

        // write the same thing as recursion
        // small calculation
        int notTake=usingMemoizationHelper(currIndex-1, arr, target, dp);

        int take=0;
        if(arr[currIndex]<=target)
        {
            take=usingMemoizationHelper(currIndex-1, arr, target-arr[currIndex], dp);
        }

        return dp[currIndex][target] = take + notTake;
    }
    int usingMemoization(int currIndex, vector<int>&arr, int target, int n)
    {
        // creating a dp array of size [n][target+1]
        vector<vector<int>>dp(n, vector<int>(target+1, -1));

        return usingMemoizationHelper(currIndex, arr, target,  dp);
    }  
    
    // using recursion
    int usingRecursion(int currIndex, vector<int>&arr, int target)
    {
        // base case
        if(currIndex==0)
        {
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target==arr[0])
                return 1;
            else    
                return 0;
        }

        // small calculation
        int notTake=usingRecursion(currIndex-1, arr, target);

        int take=0;
        if(arr[currIndex]<=target)
        {
            take=usingRecursion(currIndex-1, arr, target-arr[currIndex]);
        }

        return take + notTake;
    }
    
    int findTargetSumWays(vector<int>&arr ,int target) 
    {
        //Your code here
        int n=arr.size();

        int totSum = 0;
        for(int i=0; i<arr.size();i++){
            totSum += arr[i];
        }
        
        //Checking for edge cases
        if(totSum-target<0) return 0;
        if((totSum-target)%2==1) return 0;

        int s2 = (totSum-target)/2;

        // return usingRecursion(n-1, arr, s2);
        return usingMemoization(n-1, arr, s2, n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends