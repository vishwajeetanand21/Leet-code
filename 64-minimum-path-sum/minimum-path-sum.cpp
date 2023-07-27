class Solution {
public:
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
        return usingMemoization(i, j, grid); 
    }
};