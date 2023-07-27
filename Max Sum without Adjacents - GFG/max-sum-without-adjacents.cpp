//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	// using tabulation
	int usingTabulation(int index, int*arr)
	{
	    int n=sizeof(arr)/sizeof(arr[0]);
	    vector<int>dp(index,-1);
	    
	    //base case
	    dp[0]=arr[0];
	    dp[1]=max(arr[0], arr[1]);
	    
	    for(int i=2;i<=index;i++)
	    {
	        int pick=arr[i]+dp[i-2];
	        int notPick=0+dp[i-1];
	        
	        dp[i]=max(pick, notPick);
	    }
	    return dp[index];
	}
	
	// using memoization
	int usingMemoizationHelper(int index, int*arr, vector<int>&dp)
	{
	    if(dp[index]!=-1)
	    {
	        return dp[index];
	    }
	    if(index==0)
	    {
	        return arr[index];
	    }
	    if(index<0)
	    {
	        return 0;
	    }
	    
	    int pick=arr[index]+usingMemoizationHelper(index-2, arr, dp);
	    
	    int notPick=0+usingMemoizationHelper(index-1, arr, dp);
	    
	    return dp[index]=max(pick, notPick);
	}
	int usingMemoization(int index, int*arr)
	{
	    int n=sizeof(arr)/sizeof(arr[0]);
	    vector<int>dp(index+1,-1); //always make the dp array of index+1
	    return usingMemoizationHelper(index-1, arr, dp); //always return the answer at (index-1)
	}
	
	
	// using recursion
	int usingRecursion(int index, int*arr)
	{
	    if(index==0)
	    {
	        return arr[index];
	    }
	    if(index<0)
	    {
	        return 0;
	    }
	    
	    // pick
	    int pick=arr[index]+usingRecursion(index-2, arr);
	    
	    // not pick
	    int notPick=0 + usingRecursion(index-1, arr);
	    
	    return max(pick, notPick);
	}
	int findMaxSum(int *arr, int n) 
	{
	    // code here
	    // return usingRecursion(n-1, arr);
	    return usingMemoization(n, arr); //always mention n here
	   //return usingTabulation(n-1, arr);
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