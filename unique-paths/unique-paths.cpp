class Solution {
public:
    /*
    LOGIC: Combinatorics Solution
    Each time we are taking an exactly m+n-2 number of steps to reach the end.
    
    Since we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

    The approach of this solution is very simple just use a for loop to calculate the m+n-2Cn-1  or m+n-2Cm-1 
    */
    // Function to calculate the value of nCr
    int nCr(int n, int r)
    {
        double ans=1;
        for(int i=1;i<=r; i++)
        {
            ans=ans*(n-r+i)/i;
        }
        return (int)ans;
    }
    int uniquePaths(int n, int m)
    {
        int N=n+m-2;
        int R=n-1;

        int ans=1;
        ans=nCr(N,R);

        return ans;
    }

    /*
    // LOGIC: DYNAMIC PROGRAMMING, for reference go to striver's documentation
    // TC: O(n*m)
    // SC: O(n*m)
    int countPath(int i, int j, int n, int m, vector<vector<int>>dp)
    {
        if(i==m-1 && j<=n-1)
            return 1;
        
        if(i>=m || j>=n)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        else
            return dp[i][j] = countPath(i+1,j,n,m,dp) + countPath(i,j+1,n,m,dp);
    }
    int uniquePaths(int n,int m)
    {
        vector<vector<int>>dp;
        for(int i=0;i<m;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                temp.push_back(-1);
            }
            dp.push_back(temp);
        }

        return countPath(0,0,n,m,dp);
    }
    */


    /* LOGIC: Refer to DSA sheet for making the recursive tree
    int countPaths(int i,int j,int n,int m)
    {
        // if i==n-1 and j==m-1 then it means you are already at the end of the matrix, in this case return 1
        if(i==(n-1)&&j==(m-1)) 
            return 1;
        
        // if i>=n or j>=m thne ir means that you are going out of the boundaries, in this case return 0
        if(i>=n||j>=m) return 0;

        else
        // call the recursive function(i+1,j,n,m)-> going down
        // call the recursive function(i,j+1,n,m)-> going right
        // And finally add the sum of both the recursive functions 
            return countPaths(i+1,j,n,m)+countPaths(i,j+1,n,m);
    }
    int uniquePaths(int m, int n) {
        // calling a helper function to calculate the answer
        return countPaths(0,0,m,n);
    }
    */
};
// _ _ 
// _ _
// _ _