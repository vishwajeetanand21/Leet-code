//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:

	int findGCD(int a, int b)
	{
        int maxi=max(a,b);
	    int mini=min(a,b);
	    
	    int rem;
	    
	    while(maxi>0 && mini>0)
	    {
	        rem=maxi%mini;
	        
	        maxi=mini;
	        mini=rem;
	    }
	    
	    if(mini==0)
	        return maxi;
	}
    int gcd(int N, int arr[])
    {
    	// Your code goes here
    	
    	int ans=0;
    	for(int i=0;i<N;i++)
    	{
    	    ans=findGCD(ans, arr[i]);
    	}
    	
    	return ans;
    }
};


//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}
// } Driver Code Ends