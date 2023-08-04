//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    void mergeTwoArr(vector<int>&part1, vector<int>&part2, int n, int m, vector<int>&arr)
    {
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(part1[i]<=part2[j])
            {
                arr.push_back(part1[i]);
                i++;
            }
            else
            {
                arr.push_back(part2[j]);
                j++;
            }
        }
        while(i<n)
        {
            arr.push_back(part1[i]);
            i++;
        }
        while(j<m)
        {
            arr.push_back(part2[j]);
            j++;
        }
    }
    double MedianOfArrays(vector<int>& part1, vector<int>& part2)
    {
        // Your code goes here
        int n=part1.size();
        int m=part2.size();

        vector<int>arr;

        mergeTwoArr(part1, part2, n, m, arr);

        int arrSize=arr.size();

        double ans;

        if(arrSize %2==0)
        {
            int a=arr[arrSize/2];
            int b=arr[(arrSize-1)/2];

            ans=(double)(a+b)/2;
        }
        else
        {
            ans=arr[arrSize/2];
        }

        return ans;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends