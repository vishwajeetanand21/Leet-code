//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    long long int numberOfDigits(long long int n)
        {
            return (floor)(log10(n)+1);
        }
		long long int reverse_digit(long long int n)
		{
		    // Code here
    		long long int ans=0;
            long long int placeValue=pow(10,numberOfDigits(n));
            while(n>0 && placeValue>0)
            {
                long long int digit=n%10;
                
                ans+= digit*placeValue;
                
                placeValue=placeValue/10;
                n/=10;
            }
            return ans/10;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int n;
    	cin >> n;
    	Solution ob;
    	long long int  ans = ob.reverse_digit(n);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends