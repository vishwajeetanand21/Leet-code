//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:

    /*
    LOGIC:
            "aebcbda"
            
            a,e,b,c,b,d,a
            
            Find the characters with longest palindromic subsequence
            
            (a),e,(b),(c),(b),d,(a)             "abcba" is the longest palindromic subsequence
            
            Remove the non palindromic subsequence which is 'e' and 'd'
            
        THEREFORE RETURN
            LENGTH OF ORIGINAL STRING - LENGTH OF LONGEST PALINDROMIC SUBSEQUENCE
    */
    
    // using tabulation
    int longestCommonSubsequence(string str1, string str2)
    {
        int n=str1.size();
    
        // creating a dp array of size [n+1][n+1]
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    
        // initializing the dp array for the base case
        for(int i=0; i<=n;i++)
            dp[i][0]=0;
        for(int j=0; j<=n; j++)
            dp[0][j]=0;
    
        // writing the nested loops
        for(int i=1;i<=n; i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]= 0 + max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
    
        return dp[n][n];
    }
    int longestPalindromeSubseq(string str1) 
    {
        // making the reverse of str1
        string str2=str1;
        
        reverse(str2.begin(), str2.end());
    
        return longestCommonSubsequence(str1, str2);
    }
      

    int minimumNumberOfDeletions(string str) 
    { 
        // code here
        int n=str.size();
        
        return n - longestPalindromeSubseq(str);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends