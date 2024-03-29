class Solution {
public:
    //METHOD 2: using STL in C++
    
    void nextPermutation(vector<int>& arr)
    {
        next_permutation(arr.begin(), arr.end());
    }
    


    /*
    METHOD 1: OPTIMAL SOLUTION
    STEP 1: Find the breaking point where arr[i]<arr[i+1] 
    NOTE: Traverse from right to left not from left to right
    For example (2,1,5,4,3,0,0) here 1<5 then store it in idn variable
    In case the breaking point (arr[i]<arr[i+1]) doesn't exist 
    then simple reverse the array, it will be the next permutation
    {The next permutation of 321 will be 123}
    As of now idn=2 (3rd index)

    STEP 2: Find the next greater element from the right half (5,4,3,0,0) and swap it with arr[idn]
    The next greatest element in the right half is 3
    Therefore we will swap 3 with 1
    As of now the our array will look like 
    (2,3,5,4,1,0,0) and idn=1

    STEP 3: Then reverse the right half (5,4,1,0,0)->(0,0,1,4,5)
    The whole array will be like (2,3,0,0,1,4,5) this is our
    
    void nextPermutation(vector<int>& arr) 
    {
        int idx=-1; // variable to store the break point index
        int n=arr.size(); //variable to store the size of the array

        // Step 1: Find the break point:
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                idx=i;//index i is the break point. Here idx=2(3rd index) because 1<5
                break;
            }
        }
        //if the break point doesn't exist-> then simply reverse the whole array
        if(idx==-1)
        {
            reverse(arr.begin(),arr.end());
        }

        // Step 2: Find the next greater element and swap it with arr[idx]:
        else
        {
            int prev=idx;
            for(int i=idx+1;i<n;i++)
            {
                if(arr[i]>arr[idx-1] && arr[i]<=arr[prev])
                {
                    prev=i; //this is the next greatest element, which is 3
                }
            }
            //swaping the arr[idx] with the next greatest element
            swap(arr[idx-1],arr[prev]);

            // Step 3: Reverse the right half
            reverse(arr.begin()+idx, arr.end());
        }
    }
    */
};