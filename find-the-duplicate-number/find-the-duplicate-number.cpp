#include <algorithm>
class Solution 
{

public:

int findDuplicate(vector<int>& arr) 
{
	//step 1: initialize the slow and fast pointer at the starting element
	int slow=arr[0];
	int fast=arr[0];

	//step 2: move the slow pointer one step at a time => slow=arr[slow]
	// 		  move the fast pointer two step at a time => fast=arr[arr[fast]]
	// where ever they meet stop
	do
	{
		slow=arr[slow];
		fast=arr[arr[fast]];
	}while(slow!=fast);

    // Step 3: initialize the fast pointer to the starting of the array
    fast=arr[0];

   	// step 4: then again move both the pointers
	// but this time both pointer should move one step at a time
	// the place where they collide is the duplicate element 
	while(slow!=fast)
	{
		slow=arr[slow];
		fast=arr[fast];
	}

	return fast;
}

/*Solution :
Step 1 : Find “min” and “max” value in the given array. It will take O(n).
Step 2 : Find XOR of all integers from range “min” to “max” ( inclusive ).
Step 3 : Find XOR of all elements of the given array.
Step 4 : XOR of Step 2 and Step 3 will give the required duplicate number.
NOTE: THIS METHOD WILL FAIL FOR [2,2,2,2,2,2,2]
      THEREFORE THE ELEMENTS MUST IN IN RANGE (a,b)

    int findDuplicate(vector<int>& arr)
    {
        int n=arr.size();

        // step 1: find the maximum and the minimum from the array
        int maximum=INT_MIN, minimum=INT_MAX;
        for(int i=0;i<n;i++)
        {
            maximum=max(arr[i], maximum);
            minimum=min(arr[i], minimum);
        }

        // step 2: find XOR of all integers from range [minimum, maximum]
        int minXORmax=minimum;
        for(int i=minimum+1;i<=maximum;i++)
        {
            minXORmax ^= i;
        }

        // step 3: find XOR of all elements of the given array
        int allXOR=arr[0];
        for(int i=1;i<n;i++)
        {
            allXOR ^= arr[i];
        }

        // step 4: finally find the XOR of step 2 and 3
        int ans= minXORmax ^ allXOR;
        
        return ans;
    }
    */
    // LOGIC: It's a brute force approach by using sorting 
    /*
    int findDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==nums[i+1])
            {
                return nums[i];
            }
        }
        return -1;
    }*/
};