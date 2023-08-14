//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printDiamond(int n) 
    {
        // to print the upper part of the triangle
        for(int i=1; i<=n;i++)
        {
            // to print part A(space)
            for(int j=1;j<=n-i;j++)
            {
                cout<<" ";
            }
            //to print part B
            for(int j=1;j<=i;j++)
            {
                cout<<"* ";
            }
            // do not print part C in this question
            cout<<endl;
        }
        
        // now copy the above code and make changes in the row condition to print the inverted part
        
        // to print the upper part of the triangle
        for(int i=n; i>=1;i--)
        {
            // to print part A(space)
            for(int j=1;j<=n-i;j++)
            {
                cout<<" ";
            }
            //to print part B
            for(int j=1;j<=i;j++)
            {
                cout<<"* ";
            }
            // do not print part C in this question
            cout<<endl;
        }
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends