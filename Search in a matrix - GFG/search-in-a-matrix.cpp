//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int matSearch (vector <vector <int>> &mat, int N, int M, int X)
    {
        // calculating the number of rows
    int n=mat.size();
    // calculating the number of columns
    int m=mat[0].size();
    
    // declaring the pointers
    int row=0; //row will be pointing at the 0th row 
    int col=m-1; //col will be pointing at the 0th column 
    
    while(row<n && col>=0)
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
    /*
	int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int row=0;
	    int col=M-1;
	    
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
	}*/
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