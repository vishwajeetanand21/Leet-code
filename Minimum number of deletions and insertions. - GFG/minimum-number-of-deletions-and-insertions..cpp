//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:

    /*
        LOGIC: 
    
        str1="abcd"     str2="anc"
    
        STEP 1: Keep the LONGEST COMMON SUBSEQUENCE in tact
    
              (a),b,c,(d)       (a),n,(c)
    
    
        STEP 2: Remove the chcracters from str1 which are not the part of LCS i.e: (b,d)
    
              Delete: (b,d) from str1
    
              str1= a,c
    
        STEP 3: From the character which are not the part of LCS in str2 i.e: (n)
                insert it to str1
    
              Insert: (n) to str1
    
              str1=a,n,c
    
        STEP 4: return characters of DELETE+INSERT
                                    (b,c)+(n)
                                        2+1
                                         3
    
    
    
    
        "abcd"----2 deletion(b,c)---->"ac"-------1 insertion(n)------>"anc"
    */
    int longestCommonSubsequence(string &str1, string &str2)
    {
        int m=str1.size();
        int n=str2.size();
    
        // creating a dp array of size [m+1][n+1]   1 based indexing
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    
        // initializing the dp array for the base case
        for(int i=0;i<=m;i++)
            dp[i][0]=0;
        for(int j=0;j<=n;j++)
            dp[0][j]=0;
    
        // writing the nested loops
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j]=1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]= 0 + max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
    
        return dp[m][n];
    }	

	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
        /*
            DELETION=  m - LCS(str1, str2)
            INSERTION= n - LCS(str1, str2)
    
            DELETION + INSERTION = (m - LCS) + (n - LCS)
                                 =  m - LCS  +  n - LCS
                                 =  m + n - 2(LCS)
    
            
            
            THEREFORE we have to return 
            m + n - 2(LCS)
        */
    
        int m=str1.size();
        int n=str2.size();
    
        return m+n-(2*longestCommonSubsequence(str1, str2));
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends