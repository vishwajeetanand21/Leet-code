//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here

    	int totalSum=0;
    	for(int i=0;i<n;i++)
    		totalSum+=arr[i];
    	
    
    	int k=totalSum;
    
    	// create a 2-D dp array of size [n+1][k+1]
    	vector<vector<bool>>dp(n+1, vector<bool>(k+1, false));
    
    	
    	// initialize the dp array
    	for(int i=0;i<n;i++)
    	{
    		dp[i][0]=true;
    	}
    	dp[0][arr[0]]=true;
    	
    	// write the nested loops
    	for(int index=1;index<n;index++)
    	{
    		for(int target=1;target<=k;target++)
    		{
    			// copy the same thing which is mentioned in the memoization step and change the recursive function to dp[][]
    			// not pick
    			bool notPick=dp[index-1][target];
    			
    			// pick 
    			bool pick=false;
    			if(arr[index]<=target)
    			{
    				pick=dp[index-1][ target-arr[index] ];
    			}
    			
    			dp[index][target] = notPick | pick;
    		}
    	}
    
    	int mini=1e9;
    	for(int s1=0; s1<=totalSum/2; s1++)
    	{
    		if(dp[n-1][s1]==true)
    		{
    			mini=min(mini, abs( (totalSum-s1) -s1 ));
    		}
    	}
    
    	return mini;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends