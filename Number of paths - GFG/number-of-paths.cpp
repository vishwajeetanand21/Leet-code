//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends

// using memoization
int usingMemoizationHelper(int i, int j, vector<vector<int>>& dp) 
{
    if (dp[i][j] != -1) 
    {
        return dp[i][j];
    }

    // base case IMPORTANT
    if (i == 1 && j == 1) 
    {
        return 1;
    }
    if (i <=0 || j <= 0) 
    {
        return 0;
    }

    int up = usingMemoizationHelper(i - 1, j, dp);
    int left = usingMemoizationHelper(i, j - 1, dp);

    return dp[i][j] = up + left;
}
int usingMemoization(int i, int j)
{
    vector<vector<int>> dp(i+1, vector<int>(j+1, -1));
    return usingMemoizationHelper(i, j, dp);
}

// using recursion
int usingRecursion(int i, int j)
{
    // base case
    if(i==0 && j==0)
    {
        return 1;
    }
    if(i<0 || j<0)
    {
        return 0;
    }
    
    int up=usingRecursion(i-1, j);
    int left=usingRecursion(i, j-1);
    
    return up+left;
}
long long  numberOfPaths(int a, int b)
{
    // Code Here
    // return usingRecursion(a-1,b-1);
    return usingMemoization(a, b);
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends