class Solution {
public:
    // using tabulation
    int usingTabulation(int n, int m, vector<vector<int>>&mat)
    {
        vector<vector<int>>dp(n, vector<int>(m,-1));

        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
            {
                int northWest=1e9, northEast=1e9;
                if (i==0) 
                    dp[i][j] = mat[i][j];
                
                else
                {
                    int north=dp[i-1][j] + mat[i][j];

                    if (j>0)
                        northWest=dp[i-1][j-1] + mat[i][j];
                    if (j<m-1) 
                        northEast=dp[i-1][j+1] + mat[i][j];

                        
                    dp[i][j] = min(north, min(northEast, northWest));
                }
            }
        }
        int maxi=INT_MAX;
        for (int j=0; j<m; j++)
        {
            maxi=min(maxi, dp[n-1][j]);
        }
        return maxi;
    }

    // using memoization
    int usingMemoizationHelper(int currRow, int currCol, vector<vector<int>>&mat, vector<vector<int>>&dp)
    {
        // check for the boundary condition first
        if(currCol<0 || currCol>=mat[0].size())
            return 1e9;
        // base case
        if(currRow==0)
            return mat[0][currCol];
        
        // now check the dp array
        if(dp[currRow][currCol]!=-1)
            return dp[currRow][currCol];
    
        // discover all the paths
        int northWest=mat[currRow][currCol] + usingMemoizationHelper(currRow-1, currCol-1, mat, dp);
        int north=mat[currRow][currCol] + usingMemoizationHelper(currRow-1, currCol, mat, dp);
        int northEast=mat[currRow][currCol] + usingMemoizationHelper(currRow-1, currCol+1, mat,dp);
        
        return dp[currRow][currCol] = min(north, min(northWest, northEast));
    }
    int usingMemoization(int currRow, int currCol, vector<vector<int>>&mat)
    {
        int n=mat.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        return usingMemoizationHelper(currRow, currCol, mat, dp);
    }
    
    // using recursion
    int usingRecursion(int currRow, int currCol, vector<vector<int>>&mat)
    {
        // check for the boundary condition first
        if(currCol<0 || currCol>=mat[0].size())
            return 1e9;
        // base case
        if(currRow==0)
            return mat[currRow][currCol];
        
        // discover all the paths
        int northWest=mat[currRow][currCol] + usingRecursion(currRow-1, currCol-1, mat);
        int north=mat[currRow][currCol] + usingRecursion(currRow-1, currCol, mat);
        int northEast=mat[currRow][currCol] + usingRecursion(currRow-1, currCol+1, mat);
        
        return min(north, min(northWest, northEast));
    }
    int minFallingPathSum(vector<vector<int>>& mat) 
    {
       // code here

        int n=mat.size();

        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            // int a=usingRecursion(n-1, j, mat);
            // int a=usingMemoization(n-1, j, mat);
            int a=usingTabulation(n, n, mat);
            
            ans=min(ans, a);
        }
        return ans;   
    }
};