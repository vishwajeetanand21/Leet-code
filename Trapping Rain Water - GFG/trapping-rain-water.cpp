//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
// LOGIC
/*
Follow the steps mentioned below to implement the approach:

->Create two arrays left[] and right[] of size N. 
Create a variable (say max) to store the maximum found till a certain index during traversal.
->Run one loop from start to end: 
->In each iteration update max and also assign left[i] = max.
->Run another loop from end to start: 
    ->In each iteration update max found till now and also assign right[i] = max.
->Traverse the array from start to end.
    ->The amount of water that will be stored in this column is min(left[i], right[i]) – array[i]
    ->Add this value to the total amount of water stored
->Print the total amount of water stored.

*/
        
        // code here
        int left[n], right[n];
        
        int maximum_left = left[0] = arr[0];
        int maximum_right = right[n-1] = arr[n-1];
        
        
        // filling left array and traversing from left to right
        for(int i=1;i<n;i++)
        {
            if(arr[i]>maximum_left)
            {
                maximum_left=arr[i];
            }
            left[i]=maximum_left;
        }
        
        // filling right array and traversing from right to left
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>maximum_right)
            {
                maximum_right=arr[i];
            }
            right[i]=maximum_right;
        }
        
        // calculating the sum
        long sum=0;
        for(int i=0;i<n;i++)
        {
            sum += min(left[i], right[i]) - arr[i]; //important formulae
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends