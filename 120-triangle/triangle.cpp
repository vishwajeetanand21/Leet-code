class Solution {
public:
    // using memoization
    int usingMemoizationHelper(int currRow, int currCol, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp)
    {
    	// first write the base case
    	if(currRow==n-1)
    	{
    		return triangle[currRow][currCol];
    	} 
    	// there is no boundary condition for this question
    
    	// now check for the dp array
    	if(dp[currRow][currCol]!=-1)
    	{
    		return dp[currRow][currCol];
    	}
    
    
    	int south=triangle[currRow][currCol] + usingMemoizationHelper(currRow+1, currCol, n, triangle, dp);
    	int southEast=triangle[currRow][currCol] + usingMemoizationHelper(currRow+1, currCol+1, n, triangle, dp);
    
    	return dp[currRow][currCol] = min(south, southEast);
    }
    int usingMemoization(int currRow, int currCol, int n, vector<vector<int>>&triangle)
    {
    	vector<vector<int>>dp(n, vector<int>(n,-1));
    	return usingMemoizationHelper(currRow, currCol, n, triangle, dp);
    }
    
    // using recursion
    int usingRecursion(int currRow, int currCol,int n, vector<vector<int>>&triangle)
    {
    	// write the base case
    	if(currRow==n-1)
    	{
    		return triangle[currRow][currCol];
    	}
    	// there is no boundary condition for this question
    
    	int south=triangle[currRow][currCol] + usingRecursion(currRow+1, currCol, n, triangle);
    	int southEast=triangle[currRow][currCol] + usingRecursion(currRow+1, currCol+1, n, triangle);
    
    	return min(south, southEast);
    }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        // Code here
        int n=triangle.size();
        // return usingRecursion(0, 0, n, triangle);
        return usingMemoization(0, 0, n, triangle) ;
    }
};