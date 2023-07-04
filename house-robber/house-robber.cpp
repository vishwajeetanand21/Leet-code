class Solution {
public:
    /*
    LOGIC: The logic of this question is same as finding the max sum from the sub-sequence without ajdacents
    */
    // using variables
    int usingVariables(int index, vector<int>&arr)
    {
        if(index==0)
        {
            return arr[0];
        }

        int a=arr[0];
        int b=max(arr[0], arr[1]);
        int c; 

        for(int i=2;i<arr.size();i++)
        {
            int pick=arr[i]+a;
            int notPick= 0 + b;

            c=max(pick, notPick);
            a=b;
            b=c;
        }
        return b; //IMPORTANT Here we have to return b not c
    }

    //using tabulation
    int usingTabulationHelper(int index, vector<int>&arr, vector<int>&dp)
    {
        int n=arr.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return arr[0];
        }


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
    int usingTabulation(int index, vector<int>&arr)
    {
        int n=arr.size();

        vector<int>dp(n,-1);

        return usingTabulationHelper(index,arr,dp);
    }

    // using memoization
    int usingMemoizationHelper(int index, vector<int>&arr, vector<int>&dp)
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
        int pick=arr[index] + usingMemoizationHelper(index-2, arr, dp);
        int notPick = 0 + usingMemoizationHelper(index-1, arr, dp);

        return dp[index]=max(pick, notPick);
    }
    int usingMemoization(int index, vector<int>&arr)
    {
        int n=arr.size();

        vector<int>dp(n, -1);

        return usingMemoizationHelper(index, arr, dp);
    }

    // using recursion
    int usingRecursion(int index, vector<int>&arr)
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
        int notPick= 0 + usingRecursion(index-1, arr);

        return max(pick, notPick);
    }
    int rob(vector<int>& arr) 
    {
        int n=arr.size();

        // return usingRecursion(n-1, arr);
        // return usingMemoization(n-1, arr);
        return usingTabulation(n-1, arr);
        // return usingVariables(n-1, arr);
    }
};