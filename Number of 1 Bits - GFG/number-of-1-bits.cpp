//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    /*
    LOGIC: n= 13
    
         n= 1 1 0 1 
       n&1= 1 1 0 1  count=1
       n=n>>1
       
         n= 0 1 1 0
       n&1= 0 0 0 1  count=1
       n=n>>1
       
         n= 0 0 1 1
       n&1= 0 0 0 1  count=2
       n=n>>1
       
         n= 0 0 0 1
       n&1= 0 0 0 1 count=3
       n=n>>1
       
         n= 0 0 0 0
         return count
        
    */
    int setBits(int n) 
    {
        // Write Your Code here
        int count=0;
        
        while(n!=0)
        {
            if(n&1==1)
            {
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends