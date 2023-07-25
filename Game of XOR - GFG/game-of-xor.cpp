//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int n , int arr[]) 
    {
        // code here
        if(n%2==0) //even
        {
            return 0;
        }
        else
        {
            int evenIndexElement=0;
            for(int i=0;i<n;i+=2)
            {
                if(i<n)
                {
                    evenIndexElement^=arr[i];
                }
            }
            return evenIndexElement;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends