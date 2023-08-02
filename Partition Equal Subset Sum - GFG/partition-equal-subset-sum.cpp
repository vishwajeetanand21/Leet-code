//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // using memoization
    bool usingMemoizationHelper(int index, int*arr, int target, vector<vector<int>>&dp)
    {
    	// first write the base case same as the recursive function
    	if(target==0)
    	{
    		return true;
    	}
    	if(index==0)
    	{
    		return arr[index]==target;
    	}
    	
    	// now check the dp array 
    	if(dp[index][target]!=-1)
    	{
    		return dp[index][target];
    	}
    	
    	// now copy the same thing which is writen in recursion code
    	// not pick
    	bool notPick=usingMemoizationHelper(index-1, arr,  target, dp);
    	
    	// pick 
    	bool pick=false;
    	if(arr[index]<=target)
    	{
    		pick=usingMemoizationHelper(index-1, arr, target-arr[index], dp);
    	}
    	
    	return dp[index][target] = notPick | pick;
    }
    bool usingMemoization(int index, int *arr, int k)
    {
    	// create a dp of size [n+1][k+1]
    	int n=index+1;
    	vector<vector<int>>dp(n, vector<int>(k+1,-1));
    
    	return usingMemoizationHelper(index, arr, k, dp);
    }



    // using recursion
    bool usingRecursion(int index, int* arr, int target)
    {
    	// base cases
    	// 1. if the target will be 0, then empty subset will always be equal to 0
    	if(target==0)
    	{
    		return true;
    	}
    	// 2. if there is only 1 element and if that element is equal to the target, then return true 
    	if(index==0)
    	{
    		return arr[index]==target;
    	}
    	
    	// not pick
    	bool notPick=usingRecursion(index-1, arr, target);
    	
    	// pick 
    	bool pick=false;
    	if(arr[index]<=target) //IMPORTANT: if the current element is greater than the target, then there is no use to pick the current element
    	{
    		// only if the current element<= target then pick the element, otherwise leave it 
    		pick=usingRecursion(index-1, arr, target-arr[index]);
    	}
    	
    	// if any of the recursive call return us TRUE, it means there exist a setset which has the sum equal to the target
    	return notPick | pick;
    }
    int equalPartition(int n, int arr[])
    {
        // code here
    	int totalSum=0;
    	for(int i=0;i<n;i++)
    	{
    		totalSum+=arr[i];
    	}
    
    	if(totalSum %2 ==1) //if the total sum is odd, we cannot divide it into 2 parts
    	{
    		return false;
    	}
    
    	/* now is the total sum is even, we can divide it into 2 equal parts
    		now the question becomes easy like previous question
    		Subset sum is equal to target (where target=totalSum/2)
    	*/
    
    	int k= totalSum/2;
    
    	// return usingRecursion(n-1, arr, k);
    	return usingMemoization(n-1, arr, k);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends