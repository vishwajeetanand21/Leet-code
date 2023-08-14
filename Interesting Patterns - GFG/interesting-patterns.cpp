//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<string> interestingPattern(int n) 
    {
        // code here
        int x=2*n-1;
        
        vector<string>ans;
        
        for(int i=1;i<=x;i++)
        {
            string smallAns="";
            for(int j=1;j<=x;j++)
            {
                int top=i-1;
                int left=j-1;
                int right=x-i;
                int down=x-j;
                
                int temp = n - min( min(top,down) , min(left,right) );
                
                char temp2=temp+'0';
                
                smallAns.push_back(temp2);
            }
            ans.push_back(smallAns);
        }
        return ans;
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
        vector<string> v = ob.interestingPattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}
// } Driver Code Ends