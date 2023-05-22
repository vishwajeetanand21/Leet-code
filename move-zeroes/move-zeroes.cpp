class Solution 
{
public:
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
    /*
    0 1 0 3 12
    1 0 0 3 12
    1 3 0 0 12
    1 3 12 0 0*/
};