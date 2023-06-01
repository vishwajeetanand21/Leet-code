//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	
	/*
	LOGIC: Here we will maintain a unordered map to store the element and it's frequency
	       And we will traverse from left to right in the array
	       We will store the current element as currElement
	       and we will calcualte the more needed element by target-currElement
	       and if that moreNeeded element is already present in our map then we will return TRUe
	       Otherwise we will store the currentElement in a map
	       
	       After traversing the array if we didn't find the sum
	       Then we will simply return FALSE
	*/
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    unordered_map<int, int>myMap;
	    
	    for(int i=0;i<n;i++)
	    {
	        int currElement=arr[i];
	        int moreNeeded=x-currElement;
	        
	        if(myMap.find(moreNeeded) != myMap.end())
	        {
	            return 1;
	        }
	        myMap[currElement]++;
	    }
	    return 0;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends