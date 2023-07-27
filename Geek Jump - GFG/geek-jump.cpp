//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // using variables
    int usingVariables(int index, vector<int>&height)
    {
        // base case
        if(index==0)
        {
            return 0;
        }
        
        int a=0, b=0, c;
        
        for(int i=1;i<=index;i++)
        {
            int jumpTwo=INT_MAX;
            
            int jumpOne=b+abs(height[i]-height[i-1]);
            
            if(i>1)
            {
                jumpTwo=a+abs(height[i]-height[i-2]);
            }
            
            c=min(jumpOne, jumpTwo);
            
            a=b;
            b=c;
        }
        return c;
    }
  
    // using tabulation
    int usingTabulation(int index, vector<int>&height)
    {
        int n=height.size();
        
        vector<int>dp(n+1, -1);
        
        // base case
        dp[0]=0;
        
        for(int index=1;index<=n;index++)
        {
            // do the same thing which we have done in the memoization stage
            int jumpTwo=INT_MAX;
            
            int jumpOne=dp[index-1]+abs(height[index]-height[index-1]);
            
            if(index>1)
            {
                jumpTwo=dp[index-2]+abs(height[index]-height[index-2]);
            }
            
            dp[index]=min(jumpOne, jumpTwo);
        }
        
        return dp[n-1];
    }
    
    // using memoization
    int usingMemoizationHelper(int index, vector<int>&height, vector<int>&dp)
    {
        // base case
        if(index==0)
        {
            return 0;
        }
        
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        
        int jumpTwo=INT_MAX;
        
        int jumpOne=usingMemoizationHelper(index-1, height,dp)+abs(height[index]-height[index-1]);
        
        if(index>1)
        {
            jumpTwo=usingMemoizationHelper(index-2, height,dp)+abs(height[index]-height[index-2]);
        }
        
        return dp[index]=min(jumpOne, jumpTwo);
    }
    int usingMemoization(int index, vector<int>&height)
    {
        vector<int>dp(index+1,-1);
        return usingMemoizationHelper(index-1, height,dp);
    }
    
    
    // using recursion
    int usingRecursion(int index, vector<int>&height)
    {
        // base case
        if(index==0)
        {
            return 0;
        }
        
        int jumpTwo=INT_MAX;
        
        int jumpOne=usingRecursion(index-1, height)+abs(height[index]-height[index-1]);
        
        if(index>1)//if the index will be greater than 1, then only we can make two jump
        // otherwise if the index is 1 and if we do two left jumps then we will go out of the boundary
        {
            jumpTwo=usingRecursion(index-2,height)+abs(height[index]-height[index-2]);
        }
        return min(jumpOne, jumpTwo);
    }
    int minimumEnergy(vector<int>& height, int n) 
    {
        // Code here
        // return usingRecursion(n-1, height);
        return usingMemoization(n, height);
        // return usingTabulation(n-1, height);
        // return  usingVariables(n-1, height);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends