//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    /*
    1. Initialize a variable left to 0. This variable keeps track of the index of the last unique element in the modified array.

    2. Iterate through the array arr starting from index 1 (right variable).

    3. Check if the element at index left is not equal to the element at index right. If they are not equal, it means we have encountered a new unique element.

    4. Increment left by 1 to move to the next position in the modified array.

    5. Assign the value of the unique element (arr[right]) to the current position in the modified array (arr[left]).

    6. Repeat steps 3-5 until all elements in the original array have been processed.

    7. Return left + 1 as the size of the modified array. Adding 1 accounts for the fact that array indices are zero-based.
    */
    int remove_duplicate(int arr[],int n){
        // code here
        int left=0;
    	for(int right=1;right<n;right++)
    	{
    		if(arr[left] != arr[right])
    		{
    			left++;
    		}
    		arr[left]=arr[right];
    	}
    	return left+1;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends