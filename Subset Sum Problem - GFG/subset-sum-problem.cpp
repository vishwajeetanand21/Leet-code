//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // using tabulation
    bool usingTabulation(vector<int>&arr, int n, int k)
    {
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
        
        // our answer will be on the bottom-right cell of the dp matrix
        return dp[n-1][k];
    }



    // using memoization
    bool usingMemoizationHelper(int index, vector<int>&arr, int n, int target, vector<vector<int>>&dp)
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
        bool notPick=usingMemoizationHelper(index-1, arr, n, target, dp);
        
        // pick 
        bool pick=false;
        if(arr[index]<=target)
        {
            pick=usingMemoizationHelper(index-1, arr, n, target-arr[index], dp);
        }
        
        return dp[index][target] = notPick | pick;
    }
    bool usingMemoization(int index, vector<int>&arr, int n, int target)
    {
        // make a 2D dp array of size [n+1][target+1]
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        
        return usingMemoizationHelper(index, arr, n, target, dp);
    }



    // using recursion 
    bool usingRecursion(int index, vector<int>&arr, int n, int target)
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
        bool notPick=usingRecursion(index-1, arr, n, target);
        
        // pick 
        bool pick=false;
        if(arr[index]<=target) //IMPORTANT: if the current element is greater than the target, then there is no use to pick the current element
        {
            // only if the current element<= target then pick the element, otherwise leave it 
            pick=usingRecursion(index-1, arr, n, target-arr[index]);
        }
        
        // if any of the recursive call return us TRUE, it means there exist a setset which has the sum equal to the target
        return notPick | pick;
    }
    bool isSubsetSum(vector<int>arr, int k)
    {
        // code here 
        int n=arr.size();
        
        // return usingRecursion(n-1, arr, n, k);
        // return usingMemoization(n-1, arr, n, k);
        return usingTabulation(arr, n, k);
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