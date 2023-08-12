//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isPrime(int n)
    {
        // base case
        if(n==0 || n==1)
            return 0;
        
        
        // code here
        bool ans=true;
        
        for(int i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                ans=false;
                break;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isPrime(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends