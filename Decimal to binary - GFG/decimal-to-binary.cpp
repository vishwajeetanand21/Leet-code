//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

void toBinary(int n)
{
    // your code here
    vector<int>arr;
    
    while(n>0)
    {
        int remainder=n%2;
        int quotient=n/2;
        
        arr.push_back(remainder);
        
        n=quotient;
    }
    
    for(int i=arr.size()-1; i>=0;i--)
    {
        cout<<arr[i];
    }
}

//{ Driver Code Starts.

int main() {
	//code
	
	int t;
	cin>>t;
	
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    toBinary(n);
	    cout<<endl;
	}
	return 0;
}
// } Driver Code Ends