//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*
    
    str1="abzd"     str2="abcd"
    
             "" a b z d
          "" 0  0 0 0 0
          a  0  1 0 0 0
          b  0  0 2 0 0
          c  0  0 0 0 0
          d  0  0 0 0 1
          
        if str1[i-1]==str[j-1]
            dp[i][j]=1 + dp[i-1][j-1]  //add +1 to the top left diagonal cell
        else
            dp[i][j]=0
    
    and the maximum value int eh dp array will be the answer
    
    */
    int longestCommonSubstr (string str1, string str2, int m, int n)
    {
        // writing the tabulation code with some small modification
        
        // creating a dp array of size [m+1][n+1], because of 1 based indexing
        vector<vector<int>>dp(m+1, vector<int>(n+1,0));
        
        // initializing the dp array for the base case
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
            
        // answer variable
        int ans=0;
            
        // writing the nested loops
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j]= 1+ dp[i-1][j-1];
                    
                    ans=max(ans, dp[i][j]); //the maximum value in the dp array is our answer
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends