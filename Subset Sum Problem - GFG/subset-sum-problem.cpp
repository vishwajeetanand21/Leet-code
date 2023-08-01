//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // using memoization
    bool usingMemoizationHelper(int index, vector<int>& arr, int target, vector<vector<int>>&dp)
    {
        // First check the base case
        if (target == 0) 
        {
            return true;
        }
        
        if (index == 0)
        {
            return arr[0] == target;
        }
    
        // Now check the dp array
        if (dp[index][target] != -1)
        {
            return dp[index][target];
        }
    
        // Not pick
        bool notPick = usingMemoizationHelper(index - 1, arr, target, dp);
    
        // Pick
        bool pick = false;
        if (target >= arr[index])
        {
            pick = usingMemoizationHelper(index - 1, arr, target - arr[index], dp);
        }
    
        return dp[index][target] = notPick || pick;
    }
    bool usingMemoization(int index, vector<int>& arr, int target)
    {
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return usingMemoizationHelper(index, arr, target, dp);
    }

    // using recursion
    bool usingRecursion(int index, vector<int>&arr, int target)
    {
        // base case
        if(target==0)
        {
            return true;
        }
        if(index==0)
        {
            return arr[0]==target;
        }
    
        // not pick
        bool notPick=usingRecursion(index-1, arr, target);
    
        // pick
        bool pick=false;
        if(target >= arr[index])
        {
            pick=usingRecursion(index-1, arr, target-arr[index]);
        }
    
        // final return the answer
        return notPick | pick; //if either one is true it will be true
    }
    bool isSubsetSum(vector<int>arr, int target){
        // code here 
        int n=arr.size();
        
        // return usingRecursion(n-1, arr, target);
        return usingMemoization(n-1, arr, target);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends