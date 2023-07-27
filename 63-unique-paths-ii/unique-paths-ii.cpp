class Solution {
public:
    // using memoization
    int usingMemoizationHelper(int i, int j, vector<vector<int>>&grid, vector<vector<int>>&dp)
    {
        // first write the base case
        if(i==0 && j==0)
        {
            return 1;
        }   
        // check the boundary
        if(i<0 || j<0)
        {
            return 0;
        }
        // check for the dead cell
        if(grid[i][j]==1)
        {
            return 0;
        }
        // now check for the dp array
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }

        int up=usingMemoizationHelper(i-1, j, grid, dp);
        int left=usingMemoizationHelper(i, j-1, grid, dp);

        return dp[i][j]=up+left;
    }
    int usingMemoization(int i, int j, vector<vector<int>>&grid)
    {
        vector<vector<int>>dp(i, vector<int>(j,-1));
        return usingMemoizationHelper(i-1, j-1, grid, dp);
    }

    // using recursion
    int usingRecursion(int i, int j, vector<vector<int>>&grid)
    {
        // base case
        if(i==0 && j==0)
        {
            return 1;
        }
        // check boundary
        if(i<0 || j<0)
        {
            return 0;
        } 
        // dead cell check
        if(grid[i][j]==1)
        {
            return 0;
        }

        int up=usingRecursion(i-1, j, grid);
        int left=usingRecursion(i, j-1, grid);

        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        // edge case
        if(grid[0][0]==1)
        {
            return 0;
        }

        int n=grid.size();
        int m=grid[0].size();

        // return usingRecursion(n-1, m-1, grid);
        return usingMemoization(n, m, grid);
    }
};