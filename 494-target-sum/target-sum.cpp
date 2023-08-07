class Solution {
public:
    /*
        LOGIC: This question is exactly same as Partition with given difference question
               In which we have to divide the array into two parts such that 
               the difference of sum of both the arrays will be the target

            Eg: [1,2,3,1] target=3
            
        CASE 1: arr1=[1,3,1]    arr2=[2]
                sum1=5          sum2=2
                sum1-sum2
                5-2
                =3=target
        
        CASE 2: arr1=[2,3]      arr2=[1,1]
                sum1=5          sum2=2
                sum1-sum2
                5-2
                3=target

                Therefore there are 2 ways to divide the array such that the difference of sum of arrays will be equal to target
                THIS QUESTION IS EXACTLY SAME AS PARTITION WITH GIVEN DIFFERENCE
    */

    int usingRecursion(int currIndex, vector<int>&arr, int target)
    {
        // base case
        if(currIndex==0)
        {
            if(target==0 && arr[0]==0)
                return 2;
            if(target==0 || target==arr[0])
                return 1;
            else    
                return 0;
        }

        // small calculation
        int notTake=usingRecursion(currIndex-1, arr, target);

        int take=0;
        if(arr[currIndex]<=target)
        {
            take=usingRecursion(currIndex-1, arr, target-arr[currIndex]);
        }

        return take + notTake;
    }
    int findTargetSumWays(vector<int>& arr, int target) 
    {
        int n=arr.size();

        int totSum = 0;
        for(int i=0; i<arr.size();i++){
            totSum += arr[i];
        }
        
        //Checking for edge cases
        if(totSum-target<0) return 0;
        if((totSum-target)%2==1) return 0;

        int s2 = (totSum-target)/2;

        return usingRecursion(n-1, arr, s2);
    }
};