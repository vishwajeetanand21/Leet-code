//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    
	    // O(N) Modified Kadane Algo

        // Just iterate two times: Front and Back
	    
	    
	    long long ans= INT_MIN;
	    long long sum = 1;
	    
	   // go from left to right
	    for(int i = 0; i<arr.size(); i++){
	        sum*=arr[i];
	        ans = max(ans,sum);
	        if(sum==0) sum=1;
	    }
	    
	   // Go from right to left
	    sum = 1;
	    for(int i = arr.size()-1; i>=0; i--){
	        sum*=arr[i];
	        ans = max(ans,sum);
	        if(sum==0) sum=1;
	    }
	    
	    return ans;
	    
	    
	    
	   //  Naive Approach
	    /*long long ans=arr[0];
        for(int i=0;i<n;i++)
        {
            long long product=arr[i];
            for(int j=i+1;j<n;j++)
            {
                product*=arr[j];
                ans=max(ans, product);
            }
            ans=max(ans, product);
        }
        return ans;
        */
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends