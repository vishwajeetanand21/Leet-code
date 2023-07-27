//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    // using variables
    long long int usingVariables(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        
        long long int a=1; //for 0
        long long int b=1; //for 1
        long long int c;
        
        for(int i=2;i<=n;i++)
        {
            c=i*b;
            b=c;
        }
        return c;
    }
    
    // using tabulation
    long long int usingTabulation(int n)
    {
        vector<int>dp(n+1);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2; i<=n;i++)
        {
            dp[i]=i*dp[i-1];
        }
        return dp[n];
    }
    
    // using recursion
    long long int usingRecursion(int n)
    {
        if(n==1)
        {
            return 1;
        }
        return n*usingRecursion(n-1);
    }
    long long int factorial(int n){
        //code here
        // return usingRecursion(n);
        // return usingTabulation(n);
        return usingVariables(n);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends