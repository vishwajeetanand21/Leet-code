class Solution {
public:
    /* 
    LOGIC: The given array is having elements ranging from (1 to n) and 0 is the missing number
    for example (9,6,4,2,3,5,7,0,1) here 8 is the missing number
    the size of the array is n=9

    naturalSum=(n*(n+1))/2;

    then find the totalSum of the array 

    then the difference of naturalSum and the totalSum is the missing number
    */
    int missingNumber(vector<int>& arr) {
        int n=arr.size();

        int naturalSum=(n*(n+1))/2;

        int totalSum=0;
        for(int i=0;i<n;i++)
        {
            totalSum+=arr[i];
        }

        return naturalSum-totalSum;
    }
};