//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    // using tabulation: By performing right shift of index by 1 position
    /*
      Right shift of index by 1 position means
      i=i-1
      j=j-1
      0=-1
      1=0
      and so on
    */
    int usingTabulation(string &str1, string &str2, int m, int n)
    {
        // creating a dp of size [m+1][n+1]
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0)); //it's better to initialize the dp in tabulation as 0 when working with dp on strings
    
    
        // now write the base case
        for(int i=0;i<m;i++)
            dp[i][0]=0;
        for(int j=0;j<n;j++)
            dp[0][j]=0;
    
    
        // write the nested loops
        //why i=1 because base case has already been handled
        // why i<=m because we have right shifted the index by 1 position
        for(int i=1; i<=m; i++) 
        {
            for(int j=1;j<=n; j++)
            {
                // copy the same recurence relation from memoization
                // update the recursive function with the dp array
                
                if(str1[i-1] == str2[j-1]) //why [i-1] and [j-1] because we have right shifted the index
                {
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                // if(str1[i-1] != str2[j-1])
                else
                {
                    dp[i][j]= 0 + max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        // at last our answer will be the at the right most bottom cell
        return dp[m][n];
    }
    
    
    // using memoization
    int usingMemoizationHelper(int index1, int index2, string&str1, string &str2, vector<vector<int>>&dp)
    {
        // base case
        if(index1<0 || index2<0)
        {
            return 0;
        }
        
        // now check the dp array
        if(dp[index1][index2] != -1)
        {
            return dp[index1][index2];
        }
        
        // now copy the same thing as recursion
        // small calculation
        
        // if the current character of both the string matches
        if(str1[index1] == str2[index2])
        {
            return dp[index1][index2] = 1+ usingMemoizationHelper(index1-1, index2-1, str1, str2, dp);
        }
        // if the current character of both the string does not matches
        if(str1[index1] != str2[index2])
        {
            // to explore all the possibilities
            // first move the first index and don't move the second index
            // secondly don't move the first index but move the second index
            return dp[index1][index2] = 0 + max( usingMemoizationHelper(index1-1, index2, str1, str2, dp) , usingMemoizationHelper(index1, index2-1, str1, str2, dp) );
            // 0 + ... because there is not matching character in the string
            // finally return the maximum of both the recursion call
        }
    }
    int usingMemoization(int index1, int index2, string &str1, string &str2, int m, int n)
    {
        // create a dp array of size [m][n]
        vector<vector<int>>dp(m, vector<int>(n, -1));
        
        // pass on the same current index in the helper function 
        return usingMemoizationHelper(index1, index2, str1, str2, dp);
    }
    
    
    // using recursion
    int usingRecursion(int index1, int index2, string &str1, string &str2)
    {
        // base case: when any of the index reaches 0th index then there is no common element
        if(index1<0 || index2<0)
        {
            return 0;
        }
        
        // small calculation
        
        // if the current character of both the string matches
        if(str1[index1] == str2[index2])
        {
            return 1+ usingRecursion(index1-1, index2-1, str1, str2);
        }
        // if the current character of both the string does not matches
        if(str1[index1] != str2[index2])
        {
            // to explore all the possibilities
            // first move the first index and don't move the second index
            // secondly don't move the first index but move the second index
            return 0 + max( usingRecursion(index1-1, index2, str1, str2) , usingRecursion(index1, index2-1, str1, str2) );
            // 0 + ... because there is not matching character in the string
            // finally return the maximum of both the recursion call
        }
    }    
    int lcs(int m, int n, string str1, string str2)
    {
        // your code here
        
        // return usingRecursion(m-1, n-1, str1, str2);
        // return usingMemoization(m-1, n-1, str1, str2, m, n);
        
        // here we have done right shifting of index by 1 position
        return usingTabulation(str1, str2, m, n);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends