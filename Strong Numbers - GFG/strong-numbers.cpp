//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isStrong(int n) 
    {
	    // create a dp array and store all the factorials from 0 to 9
	    vector<int>dp(10);
	    dp[0]=1;
	    for(int i=1;i<=9;i++)
	    {
	        dp[i]=i*dp[i-1];
	    }
	    
	    // Now calculate the factorial of every digit and add it to a variable
	    int sum=0;
	    int originalNum=n;
	    
	    while(n>0)
	    {
	        int digit=n%10;
	        sum+=dp[digit];
	        
	        n=n/10;
	    }
	    
	    // if the sum of factorials of all digit is same to that number, then it is a strong 
	    if(sum==originalNum)
	    {
	        return 1;
	    }
	    return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.isStrong(N) << endl;
    }
    return 0;
}
// } Driver Code Ends