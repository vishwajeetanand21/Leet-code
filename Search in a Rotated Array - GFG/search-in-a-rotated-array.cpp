//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int low, int high, int k){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        
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
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends