class Solution {
public:
    // using tabulation
    int usingTabulation(int n, int m, vector<vector<int>>&grid)
    {
        vector<vector<int>>dp(n, vector<int>(m, -1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int up=grid[i][j];
                    int left=grid[i][j];
                    
                    if(i>0)
                        up+=dp[i-1][j];
                    else
                        up+=1e9;
                    
                    if(j>0)
                        left+=dp[i][j-1];
                    else
                        left+=1e9;
                    
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[n-1][m-1];
    }

    // using memoization
    int usingMemoizationHelper(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        // first write the base case
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        // when you go out of the boundary
        if (i < 0 || j < 0) 
        {
        return 1e9;
        }
        
        // Now check in the dp array
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        int up=grid[i][j] + usingMemoizationHelper(i-1, j, grid, dp);
        int left=grid[i][j] + usingMemoizationHelper(i, j-1, grid, dp);

        return dp[i][j]=min(up, left);
    }
    int usingMemoization(int i, int j, vector<vector<int>>&grid)
    {
        vector<vector<int>>dp(i, vector<int>(j,-1));
        return usingMemoizationHelper(i-1, j-1, grid, dp);
    }
    int usingRecursion(int i, int j, vector<vector<int>>&grid)
    {
        if(i==0 && j==0)
        {
            return grid[i][j];
        }
        if(i<0 || j<0)
        {
            return INT_MAX;
        }

        int up=grid[i][j] + usingRecursion(i-1, j, grid);
        int left=grid[i][j] + usingRecursion(i, j-1, grid);        

        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) 
    {
        int i=grid.size();
        int j=grid[0].size();

        // return usingRecursion(i-1, j-1, grid);   
        // return usingMemoization(i, j, grid); 
        return usingTabulation(i, j, grid);
    }
};