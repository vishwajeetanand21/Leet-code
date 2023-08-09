//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    /*
        LOGIC: 
                Keep the palindromic sub-sequence intack
                Do not change the position of palindromic sub-sequence

                "abcaa"
                
                Let's say longest palindromic sub-secuence is "aaa"

                [a],b,c,[a],[a]      The character inside the square box [] are palindrome

                Now add the remaining element in the string in reverse order
                a,(b,c),a,a
                a,(b,c),a,(c,b),a
                
                We have added (c,b) which is the reverse form of the non-palindromic elements

        Therefore now the string becomes
                a,b,c,a,c,b,a

        At last we can say that 
        STEP 1: Find out the length of longest palindromic sub-sequence in the original string
        STEP 2: Then we need to find the remaining elements which are not in palindrome

        At Last return 
            TOTAL LENGTH OF ORIGINAL STRING - LENGTH OF LONGEST PALINDROMIC SUBSEQUENCE

        Example 2:
            str="abcaa"

            Let's say the longest palindromic sub-sequence is "aca"

                [a],b,[c],a,[a]   The character inside the square box [] are palindrome

                a,(b),c,(a),a

                Now add the reverse of non-palindromic characters in the string

                a,(b),(a),c,(a),(b),a
                We have added (a,b) which is the reverse of (b,a) which is the non-palindromic subsequence
        
        Therefore the new string will be 
                a,b,a,c,a,b,a

        Example 3: 
            str="codingninjas"

            The longest palindromic sub-sequence in the original string is "ingni"

                c,o,d,[i,n,g,n,i],j,a,s

                (c,o,d),i,n,g,n,i,(j,a,s)

                Add (c,o,d) and (j,a,s) into the original string

                (c,o,d),(j,a,s),i,n,g,n,i,(j,a,s),(c,o,d)

                The new string becomes
                c,o,d,j,a,s,i,n,g,n,i,j,a,s,c,o,d

            Therefore we have to return

            LENGTH OF ORIGINAL STRING - LENGTH OF LONGEST PALINDROMIC SUBSEQUENCE

    */
    int longestCommonSubsequence(string &str1, string &str2)
    {
        // Writing the tabulation form of LCS 

        int m=str1.size();
        int n=str2.size();

        // creating a dp array of size [m+1][n+1]
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
                    dp[i][j]=0 + max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
    int longestPalindromicSubsequence(string &str1)
    {
        // WE KNOW THAT LONGEST COMMON SUB-SEQUENCE OF STR AND REVERSE OF STR 
        // WILL GIVE THE LONGEST PALINDROMIC SUBSEQUENCE

        string str2=str1;

        reverse(str2.begin() , str2.end());

        return longestCommonSubsequence(str1, str2);
    }

    int findMinInsertions(string str)
    {
        // code here
        int n=str.size();

        //  WE HAVE TO RETURN LENGTH OF ORIGINAL STRING-LENGTH OF LONGEST PALINDROMIC SUBSEQUENCE

        return n-longestPalindromicSubsequence(str);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends