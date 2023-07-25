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
};