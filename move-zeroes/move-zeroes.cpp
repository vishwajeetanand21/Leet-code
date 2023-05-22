class Solution 
{
public:
    /* LOGIC: We will traverse from left to right
       and we will maintain one pointer at 0th index
       whenever we get arr[i]!=0
       YES: then swap(arr[k], arr[i])
       NO: keep on traversing
    */
    void moveZeroes(vector<int>& nums) 
    {
        int k=0;//This variable will store all the number which are not equal to zero
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                int temp=nums[i];
                nums[i]=nums[k];
                nums[k]=temp;
                k++;
            }
        }
    }
    /* DRY RUN
    0 1 0 3 12
    1 0 0 3 12
    1 3 0 0 12
    1 3 12 0 0*/
};