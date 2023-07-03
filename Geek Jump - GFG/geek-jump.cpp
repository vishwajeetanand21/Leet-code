//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // using tabulation
    int usingTabluation(vector<int>&heights, int index)
    {
        int n=heights.size();
        int dp[n];
        
        dp[0]=0;
    
        for(int index=1;index<n;index++)
        {
            int jumpTwo=INT_MAX;
    
            int jumpOne=dp[index-1] + abs(heights[index] - heights[index-1]);
    
            if(index>1)
            {
                jumpTwo=dp[index-2] + abs(heights[index] - heights[index-2]);
            }
    
            dp[index]=min(jumpOne, jumpTwo);
        }
    
        return dp[n-1];
    }
  
    // using memoization
    int usingMemoizationHelper(int index, vector<int>&heights, int dp[])
    {
        if(index==0)
        {
            return 0;
        }
    
        if(dp[index]!=-1)
        {
            return dp[index];
        }
    
        int jumpTwo=INT_MAX;
    
        int jumpOne=usingMemoizationHelper(index-1, heights, dp) + abs(heights[index]-heights[index-1]);
    
        if(index>1)
        {
            jumpTwo=usingMemoizationHelper(index-2, heights, dp) + abs(heights[index]-heights[index-2]);
        }
    
        return dp[index]=min(jumpOne, jumpTwo);
    }
    int usingMemoization(vector<int>&heights, int index)
    {
        int n=heights.size();
        int dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=-1;
        }
    
        return usingMemoizationHelper(index, heights, dp);
    }
    
    // using recursion
    int usingRecursion(vector<int>&heights, int index)
    {
        if(index==0)
        {
            return 0;
        }
        
        int jumpTwo=INT_MAX;
        
        int jumpOne=usingRecursion(heights, index-1) + abs(heights[index]-heights[index-1]);
        
        if(index>1)
        {
            jumpTwo=usingRecursion(heights, index-2) + abs(heights[index]-heights[index-2]);
        }
        
        return min(jumpOne, jumpTwo);
    }
    int minimumEnergy(vector<int>& heights, int n) {
        // Code here
        // return usingRecursion(heights, n-1);
        // return usingMemoization(heights, n-1);
        return usingTabluation(heights,n-1);
        
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