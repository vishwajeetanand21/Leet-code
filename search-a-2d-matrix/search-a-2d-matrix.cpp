class Solution {
public:
/*
LOGIC: It is important to maintain 2 pointer
        row-> pointing at the 0th row
        col-> pointing at the last column(m-1)
(why col=m-1 why not 0? Because if we keep row=0 and col=0 then we are pointing at the first element
then there is no element smaller than the first element, all element are greater than first element)
THEREFORE IT IS IMPORTANT TO KEEP col POINTER AT m-1 position

    ↓
1 2 3←current element is at 3
4 5 6
7 8 9

    if the arr[row][col]==target
        return true
    
    if(arr[row][col]<target) This means that (current element < target element) 
    it is obvious that the target element is not present in current row
    it will definately be present in next or upcoming rows THEREFORE INCREASE THE ROW POINTER
        row++
    
    else This means that (current element > target element)
    it is obvious that the target element will be present in the same row
    and it will be on it's left side as targer element is less than that of current element
    THEREFORE DECREASE coL PPOOINTER
        col--
        
    if the number is not matched then simply return false
*/
    bool searchMatrix(vector<vector<int>>& arr, int target) {
    int row = 0; //set the row pointer at the starting row
    int col = arr[row].size() - 1; //set the col pointer at the last column
    
    while (row < arr.size() && col >= 0) //run the loop while row<n and col>=0
    {
        if (arr[row][col] == target)//if the current element==target element 
        {
            return true;
        }
 
        // Target lies in further row
        if (arr[row][col] < target) {
            row++;
        }
        // Target lies in previous column
        else {
            col--;
        }
    }
    return false;
    }
};