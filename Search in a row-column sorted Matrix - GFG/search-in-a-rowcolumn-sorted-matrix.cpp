//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > arr, int n, int m, int x) 
    {
        /*
        LOGIC: For each row traverse from right to left
               For each column traverse from  up to down
               
               As the element is sorted in increasing order
               if(arr[i][j]<x) 
                    This means that x will not be there in this row, so it's better to search in the next row
               if(arr[i][j]==x)
                    return 1
            
        */
        for(int i=0;i<n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(arr[i][j]<x)
                {
                    break;
                }
                if(arr[i][j]==x)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends