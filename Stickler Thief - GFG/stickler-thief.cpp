//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
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
        // int n=sizeof(arr)/sizeof(arr[0]);
        vector<int>dp(index+1,-1); //always make the dp array of size n+1
        
        return usingMemoizationHelper(index-1, arr, dp); //always return index-1
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
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // return usingRecursion(n-1, arr);
        return usingMemoization(n, arr); //always pass n here; 
        /*
        n->in the main function
        index+1->while creating the dp array
        index-1->while returning the answer
        */
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends