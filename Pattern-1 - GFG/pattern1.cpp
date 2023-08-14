//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<string> findThePattern(int N) 
    {
        // code here
        char counter='A';
        
        vector<string>answer;
        
        for(int i=1;i<=N;i++)
        {
            string temp="";
            for(int j=1;j<=N;j++)
            {
                // boundary condition
                if(i==1 || i==N || j==1 || j==N)
                {
                    temp.push_back(counter);
                    counter++;
                }
                else
                {
                    temp.push_back('$');
                }
            }
            answer.push_back(temp);
        }
        return answer;
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
        vector<string> v = ob.findThePattern(N);
        
        for(int i=0; i<v.size(); i++)
            cout<<v[i]<<endl;
    }
    return 0;
}
// } Driver Code Ends