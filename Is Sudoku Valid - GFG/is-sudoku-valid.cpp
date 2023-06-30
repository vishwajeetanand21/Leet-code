//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(vector<vector<int>>arr, int currRow, int currCol)
    {
        int digit=arr[currRow][currCol];
        
        arr[currRow][currCol]=0;
        
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
        
        arr[currRow][currCol]=digit;
        
        return true;
    }
    bool solve(vector<vector<int>>arr)
    {
        for(int currRow=0;currRow<9;currRow++)
        {
            for(int currCol=0;currCol<9;currCol++)
            {
                int digit=arr[currRow][currCol];
                
                if(digit!=0 && isSafe(arr,currRow, currCol)==false)
                {
                    return false;
                }
            }
        }
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