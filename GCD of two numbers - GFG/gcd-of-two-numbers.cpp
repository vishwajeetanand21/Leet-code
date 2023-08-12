//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd(int a, int b) 
	{ 
	    // code here
	    
        while (a > 0 && b > 0) 
        {
            if (a > b) 
                a = a % b;
            
            else 
                b = b % a;
        }
        
        if (a == 0)
            return b;
        else
            return a;
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends