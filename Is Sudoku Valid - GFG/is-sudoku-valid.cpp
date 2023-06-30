//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
/*
LOGIC: To check whether it's a valid sudoku or not
       STEP 1: Traverse in all the cells of sudoku
       STEP 2: Whenever there is a numerical digit store it in a variable 'digit'
       STEP 3: Now call a isSafe() function and pass the array, current row and current column
            (i) Replace the numbrical character with a '.'
            (ii) Then find across current row whether this digit is present or not. Do the same for current column
                 and grid 
            (iii) If the digit is present return false
            (iv) After traversing in the current row and current column and current grid if the digit is not
                 present return true
            (v) Then finally replace the '.' with the original character     
*/
    bool isSafe(vector<vector<int>>arr, int currRow, int currCol)
    {
        int digit=arr[currRow][currCol]; //storing the current digit
        
        arr[currRow][currCol]=0;//and replacing it with a 0
        
        // current row
        for(int i=0;i<9;i++)
        {
            if(arr[currRow][i]==digit)
            {
                return false;
            }
        }
        
        // current column
        for(int i=0;i<9;i++)
        {
            if(arr[i][currCol]==digit)
            {
                return false;
            }
        }
        
        // current grid
        int x=(currRow/3)*3;
        int y=(currCol/3)*3;
        
        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(arr[i][j]==digit)
                {
                    return false;
                }
            }
        }
        // replacing the 0 with the original digit
        arr[currRow][currCol]=digit;
        // finally returning true
        return true;
    }
    bool solve(vector<vector<int>>arr)
    {
        for(int currRow=0;currRow<9;currRow++)
        {
            for(int currCol=0;currCol<9;currCol++)
            {
                int digit=arr[currRow][currCol];
                // the digit should any numerical value it should not be any 0
                // and the isSafe() function should also return false
                // then only we can say that the given sudoku is not valid
                if(digit!=0 && isSafe(arr,currRow, currCol)==false)
                {
                    return false;
                }
            }
        }
        // otherwise it's a valid sudoku
        return true;
    }
    int isValid(vector<vector<int>> arr){
        // code here
        if(solve(arr))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}
// } Driver Code Ends