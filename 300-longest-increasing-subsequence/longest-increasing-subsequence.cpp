class Solution {
public:
    int longestIncreasingSubsequence(vector<int>&arr, int n)
    {
        int dp[n];
        dp[0]=1;

        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if( (arr[i]>arr[j]) && ( dp[i]<dp[j]+1 ))
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            ans=max(ans, dp[i]);
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& arr) 
    {
        int n=arr.size();

        return longestIncreasingSubsequence(arr,n);
    }
    /*
    int getAns(vector<int>&arr, int n,  int ind, int prev_index, vector<vector<int>>& dp)
    {
        
        // base condition
        if(ind == n)
            return 0;
            
        if(dp[ind][prev_index+1]!=-1)
            return dp[ind][prev_index+1];
        
        int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
        
        int take = 0;
        
        if(prev_index == -1 || arr[ind] > arr[prev_index]){
            take = 1 + getAns(arr,n,ind+1,ind,dp);
        }
        
        return dp[ind][prev_index+1] = max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        int n=nums.size();

        vector<vector<int>> dp(n,vector<int>(n+1,-1));
    
        return getAns(nums,n,0,-1,dp);
    }
    */
};