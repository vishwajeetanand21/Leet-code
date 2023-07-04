//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	//space optimization
	int usingVariables(int index, int*arr)
	{
	    if(index==0)
	    {
	        return arr[0];
	    }
	    
	    int a=arr[0];
	    int b=max(arr[0] , arr[1]);
	    int c;
	    
	    for(int i=2;i<=index;i++)
	    {
	        int pick=arr[i]+a;
	        int notPick= 0 +b;
	        
	        c=max(pick, notPick);
	        a=b;
	        b=c;
	    }
	    return c;
	}
	
	//using tabulation
	int usingTabulation(int index, int*arr)
	{
	    vector<int>dp(index+1, -1);
	    
	    dp[0]=arr[0];
	    dp[1]=max(arr[0], arr[1]);
	    
	    for(int i=2;i<=index;i++)
	    {
	        int pick=arr[i]+dp[i-2];
	        int notPick=0 + dp[i-1];
	        
	        dp[i]=max(pick, notPick);
	    }
	    
	    return dp[index];
	}
	
	
	// using memoization
	int memoizationHelper(int index, int *arr, vector<int>dp)
	{
	    if(dp[index]!=-1)
	    {
	        return dp[index];
	    }
	    if(index==0)
	    {
	        return arr[0];
	    }
	    if(index<0)
	    {
	        return 0;
	    }
	    int pick=arr[index]+memoizationHelper(index-2, arr, dp);
	    int notPick=0 + memoizationHelper(index-1, arr, dp);
	    
	    return dp[index]=max(pick, notPick);
	}
	int usingMemoization(int index, int*arr)
	{
	    vector<int>dp(index+1, -1);
	    
	    return memoizationHelper(index, arr, dp);
	}
	
	// using recursion
	int usingRecursion(int index, int*arr)
	{
	    if(index==0)
	    {
	        return arr[0];
	    }
	    if(index<0)
	    {
	        return 0;
	    }
	    
	    int pick=arr[index]+usingRecursion(index-2, arr);
	    int notPick=0+usingRecursion(index-1, arr);
	    
	    return max(pick, notPick);
	}
	
	int findMaxSum(int *arr, int n) 
	{
	    // code here
	   // return usingRecursion(n-1, arr);
	   //return  usingMemoization(n-1, arr);
	   return usingTabulation(n-1, arr);
	   //return usingVariables(n-1, arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends