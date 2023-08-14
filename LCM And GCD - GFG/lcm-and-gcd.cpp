//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long findGCD(long long A, long long B)
    {
        long long mini=min(A, B);
        long long maxi=max(A, B);
        
        while(maxi>0 && mini>0)
        {
            long long rem=maxi%mini;
            
            maxi=mini;
            mini=rem;
        }
        if(mini==0)
        {
            return maxi;
        }
    }
    long long findLCM(long long A, long long B)
    {
        // We know that: LCM x HCF = A x B
        // return (A/findGCD(A,B))*B;
        return (A*B)/findGCD(A,B);
    }
    vector<long long> lcmAndGcd(long long A , long long B) 
    {
        // code here
        long long LCM=findLCM(A,B);
        long long HCF=findGCD(A,B);
        
        vector<long long>ans;
        ans.push_back(LCM);
        ans.push_back(HCF);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends