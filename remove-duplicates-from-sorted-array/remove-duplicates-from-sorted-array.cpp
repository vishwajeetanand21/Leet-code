class Solution 
{
public:
    // Do a dry run for better understanding

        /*
    1. Initialize a variable left to 0. This variable keeps track of the index of the last unique element in the modified array.

    2. Iterate through the array arr starting from index 1 (right variable).

    3. Check if the element at index left is not equal to the element at index right. If they are not equal, it means we have encountered a new unique element.

    4. Increment left by 1 to move to the next position in the modified array.

    5. Assign the value of the unique element (arr[right]) to the current position in the modified array (arr[left]).

    6. Repeat steps 3-5 until all elements in the original array have been processed.

    7. Return left + 1 as the size of the modified array. Adding 1 accounts for the fact that array indices are zero-based.
    */

    int removeDuplicates(vector<int>& nums) 
    {
        int left=0;
        for(int right=1;right<nums.size();right++)
        {
            if(nums[left]!=nums[right])
            {
                left++;
            }
            nums[left]=nums[right];
        }
        return left+1;
    }
};