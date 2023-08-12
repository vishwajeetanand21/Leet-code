//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // counting number of digits at constant time
    int numberOfDigits2(int n)
    {
        return floor(log10(n)+1);
    }
    
    // counting number of digits using loop
    int numberOfDigits(int n)
    {
        int ans=0;
        while(n>0)
        {
            int rem=n%10;
            ans++;
            n=n/10;
        }
        return ans;
    }
    string armstrongNumber(int n)
    {
        int power=numberOfDigits2(n);
        
        int originalNum=n;
        int sum=0;
        
        while(n>0)
        {
            int digit=n%10;
            sum += pow(digit, power);
            
            n=n/10;
        }
        
        if(sum==originalNum)
            return "Yes";
        else
            return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends