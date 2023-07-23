//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
/*
OPTIMAL SOLUTION TC:O(1)

Left=3      right=6 
(3^4^5^6)=4

We know how to find the XOR from 1 to n (previous question)
XOR(6)                  XOR(2)
(1^2^3^4^5^6)           (1^2)

XOR(6) ^ XOR(2)
=(1^2^3^4^5^6)^(1^2)
=(3^4^5^6)

Therefore we can simplify the equation

XOR in range (left, right) 
= XOR(right)^XOR(left-1)

*/
    int XORfunction(int n)
    {
            if(n%4==1)
                return 1;
            if(n%4==2)
                return n+1;
            if(n%4==3)
                return 0;
            if(n%4==0)
                return n;
    }
    int findXOR(int left, int right) 
    {
        int ans=XORfunction(right) ^ XORfunction(left-1);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends