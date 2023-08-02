class Solution {
public:
    /*
    LOGIC: 
            STEP 1: First find of the total sum of the array
            STEP 2: If the total sum is odd-> we cannot divide odd sum into two equal parts
                    If the total sum is even-> we can divide the even sum into 2 equal parts
            STEP 3: If the total sum is even
                    Then the question becomes similar to the previous question
                    Subset sum equal to target (where target= totalSum/2) 
    */
    
    // using memoization
    bool usingMemoizationHelper(int index, vector<int>&arr, int k, vector<vector<int>>&dp)
    {
        if(k==0)
        {
            return true;
        }
        if(index==0)
        {
            return arr[0]==k;
        }

        if(dp[index][k]!=-1)
        {
            return dp[index][k];
        }

        // not pick
        bool notPick=usingMemoizationHelper(index-1, arr, k, dp);

        // pick
        bool pick=false;
        if(arr[index]<=k)
        {
            pick=usingMemoizationHelper(index-1, arr, k-arr[index], dp);
        }

        return dp[index][k] = notPick | pick;
    }
    bool usingMemoization(int index, vector<int>&arr, int k)
    {
        // create a dp of size [n+1][k+1]
        int n=arr.size();
        vector<vector<int>>dp(n, vector<int>(k+1,-1));

        return usingMemoizationHelper(index, arr, k, dp);
    }

    // using recursion
    bool usingRecursion(int index, vector<int>&arr, int k)
    {
        if(k==0)
        {
            return true;
        }
        if(index==0)
        {
            return arr[0]==k;
        }

        // not pick
        bool notPick=usingRecursion(index-1, arr, k);

        // pick
        bool pick=false;
        if(arr[index]<=k)
        {
            pick=usingRecursion(index-1, arr, k-arr[index]);
        }

        return notPick | pick;
    }
    
    bool canPartition(vector<int>& arr) 
    {
        int n=arr.size();

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