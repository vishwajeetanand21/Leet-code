class Solution {
public:
/*
LOGIC: 
Example: arr=[3,0,0,2,0,4]

          |
|         |
|     |   |
| _ _ | _ |
3 0 0 2 0 4


          |
| ~ ~ ~ ~ |
| ~ ~ | ~ |
| ~ ~ | ~ |
3 0 0 2 0 4

Therefore we can store 10 units of water

OVSERVATION
-> We are at the first element i.e: 3 we cannot store any water here
-> We are at the second element i.e: 0 here we can store 3 units of water
-> We are at the third element i.e: 0 here we can store 3 units of water
-> We are at the fourth element i.e: 2 here we can only store 1 unit of water
-> We are the fifth element i.e: 0 here we can store 3 units of water
-> We are the sixth element i.e: 4 here we cannot store water

Approach:
-> We are at the first element i.e: 3 we cannot store any water
    It means in the first and last element we cannot store any water
-> We are at the second element i.e: 0 we can store 3 units of water
    STEP 1: Here we need to find the maximum left boundary and maximum right boundry
    STEP 2: The maximum left bounday is 3 and maximum right boundry is 4
    STEP 3: Then we will take the minimum of both the boundry which is 3
    STEP 4: And we will subtract the current element from minimum of both the boundry 
    STEP 5: Add the value of the final sum

-> We are at the third element i.e: 0 we will repeat the same procedure
-> We are at the fourth element i.e: 2 here we can store only 1 unit of water
    Maximum left boundry: 3
    Maximum right boundry: 4
    min(3,4)=3
    subtract 2 from 3 because 2 is the height of a bar
    Add the value to the final sum
-> Repeat the process for the rest elements

*/
    int trap(vector<int>& arr) {
        int n=arr.size(); //array size

        int left[n];  //this array will store the maximum left boundry for each element
        int right[n]; //this array will store the maximum right boundry for each element

        //we cannot store any water at the first and last index, therefore initialize the first and last element
        int maximum_left=left[0]=arr[0]; 
        int maximum_right=right[n-1]=arr[n-1];

        //finding the left maximum boundry for each element
        for(int i=1;i<n;i++) // the loop starts from 1 to n-1 because we have already handled the first element
        {
            if(arr[i]>maximum_left)
            {
                maximum_left=arr[i];
            }
            left[i]=maximum_left;
        }

        // finding the right maximum boundry for each element
        for(int i=n-2;i>=0;i--) //the loop starts from n-2 to 0 because we have already handled the last element
        {
            if(arr[i]>maximum_right)
            {
                maximum_right=arr[i];
            }
            right[i]=maximum_right;
        }

        int sum=0; // variable to store the answer
        for(int i=0;i<n;i++)
        {
            sum += min(left[i], right[i])-arr[i];
            // finding the minimum of the left and right boundry
            // and subtracting the current element
            // and adding the resultant value to the answer
        }

        return sum;
    }
};