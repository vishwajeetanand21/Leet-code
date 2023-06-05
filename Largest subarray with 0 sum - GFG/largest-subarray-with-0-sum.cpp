//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {
        unordered_map<int, int>myMap;
        
        int maxLength=0;
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            {
                maxLength=i+1;
            }
            else
            {
                if(myMap.find(sum) != myMap.end())
                {
                    maxLength=max(maxLength , i-myMap[sum]);
                }
                else
                {
                    myMap[sum]=i;
                }
            }
        }
        return maxLength;
    }
    
    /* BRUTE FORCE APPROACH
    int maxLen(vector<int>&arr, int n)
    {   
        // Your code here
        int maxLength=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum+=arr[j];
                if(sum==0)
                {
                    maxLength=max(maxLength , j-i+1);
                }
            }
        }
        return maxLength;
    }*/
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends