//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    /*
    LOGIC: 
        n=25
        squareRoot=√25=5
        
        if squareRoot*squareRoot==n
            5*5==25
            return true
    */
    bool isPerfect(long long int n)
    {
        long long int squareRoot=sqrt(n);
        
        return squareRoot*squareRoot==n;
    }
    long long int isPerfectSquare(long long int n){
        // code here
        return isPerfect(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.isPerfectSquare(n) << endl;
    }
    return 0;
}

// } Driver Code Ends