//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
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
    int matSearch (vector <vector <int>> &mat, int N, int M, int X)
    {
        // declaring the pointers
        int row=0; //row will be pointing at the 0th row 
        int col=M-1; //col will be pointing at the last column 
        
        while(row<N && col>=0)
        {
            if(mat[row][col]==X)
            {
                return true;
            }
            
            if(mat[row][col]<X)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        Solution ob;
        cout << ob.matSearch (arr, n, m, x) << endl;
    }
}
// } Driver Code Ends