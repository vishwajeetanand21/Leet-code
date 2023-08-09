class Solution {
public:
    /*
    LOGIC: LONGEST COMMON SUBSEQUENCE OF STR1 AND REVERSE OF STR1 IS THE LONGEST PALINDROMIC SUBSEQUENCE
    
    get the Longest common subsequence of str1 and reverse of str1

    Explanation:

        str1="bbabcbcab"

        str1= "b(babcb)c(ab)"
        The longest palindromic sub-sequence is "babcbab"

        str2=reverse(str1)

        then 
        str2="bacbcbabb"

        str2="(ba)c(bcbab)b"

        Now find the longest common subsequence of str1 and str2 
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
};