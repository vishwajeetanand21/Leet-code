//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    /*
    LOGIC: Sorting and Binary Search

    STEP 1: Sort the whole array
    STEP 2: Traverse the whole array from 0 to n-2, 
    why we are leaving 2 elements from the last because we have to find the triplets
    STEP 3: Fix 2 pointers 
            left=i+1
            right-n-1
            and do the search similar to binary search
            if the sum of arr[i]+arr[left]+arr[right]==0
                add to the answer vector
            otherwise do the siimilar operation to binary search
    */
    
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr, arr+n);
        
        for(int i=0;i<n-2;i++)
        {
            int left=i+1;
            int right=n-1;
            
            int sum=0;
            
            while(left<right)
            {
                sum=arr[i]+arr[left]+arr[right];
                
                if(sum==0)
                {
                    return 1;
                }
                else if(sum<0)
                {
                    left++;
                }
                else
                {
                    right--;
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
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends