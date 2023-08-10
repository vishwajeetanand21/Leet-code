//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> arr, int k) 
{
    //code here
    int n=arr.size();
    
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        
        // the target is present at the middle of the array
        if(arr[mid]==k)
        {
            return mid;
        }

        // left half is sorted
        if(arr[low]<=arr[mid])
        {
            if(arr[low]<=k && k<=arr[mid])
            {
                high=mid-1;
            }
            else //element does not exist in left half
            {
                low=mid+1;
            }
        }
        else
        {
            if(arr[mid]<=k && k<=arr[high])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return -1;    
}