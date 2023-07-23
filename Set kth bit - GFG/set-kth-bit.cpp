//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    /*
    LOGIC: Making a mask and performing OR operation
    
    n=10    k=2
    
    n= 1 (0) 1 0    We have to set the 2nd index bit from 0 to 1
    
    create a mask
    mask= 1<<k
    mask= 0 1 0 0
    
    n OR mask
    1  0 1 0    |   0  1  0 0
    1 (0) 1 0   |   0 (1) 0 0
    1 1 1 0
    14
    
    
    */
    int setKthBit(int n, int k)
    {
        // Write Your Code here
        
        int mask=1<<k; // make a mask, only the kth bit will be 1 rest all the other bit will be 0
        
        return n|mask; //perform the OR operation of n and mask
    }
    
};




//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        
        Solution ob;
        int ans = ob.setKthBit(N,K);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends