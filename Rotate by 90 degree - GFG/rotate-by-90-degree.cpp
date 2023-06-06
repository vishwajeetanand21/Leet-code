//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void reverseArr(vector<int>&arr)
{
    int n=arr.size();
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}
void reverseMat(vector<vector<int>>&mat)
{
    int n=mat.size();
    
    for(int i=0;i<n;i++)
    {
        reverseArr(mat[i]);
    }
}
void transposeMat(vector<vector<int>>&mat)
{
    int n=mat.size();
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            int temp=mat[i][j];
            mat[i][j]=mat[j][i];
            mat[j][i]=temp;
        }
    }
}
void rotate(vector<vector<int> >& matrix)
{
    reverseMat(matrix);
    
    transposeMat(matrix);
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends