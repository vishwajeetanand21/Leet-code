//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // using tabulation
    int usingTabulation(int n, vector<vector<int>>&triangle)
    {
    	// create a dp array
    	vector<vector<int>>dp(n, vector<int>(n,-1));
    
    	// handling the last row
    	for(int j=0;j<n;j++)
    	{
    		dp[n-1][j]=triangle[n-1][j];
    	}
    
    	// filling the dp in bottom up fashion
    	for(int i=n-2;i>=0;i--)
    	{
    		for(int j=0; j<=i; j++)
    		{
    			int south=triangle[i][j] + dp[i+1][j];
    			int southEast=triangle[i][j] + dp[i+1][j+1];
    
    			dp[i][j]=min(south, southEast);
    		}
    	}
    	return dp[0][0];
    }
  
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
    int minimizeSum(int n, vector<vector<int>>& triangle) 
    {
        // Code here
        // return usingRecursion(0, 0, n, triangle);
        // return usingMemoization(0, 0, n, triangle) ;
        return usingTabulation(n, triangle);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends