//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:

    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<int>answer;
        
        vector<int>arr(n+1, true);
        
        arr[0]=false;
        arr[1]=false;
        
        for(int i=2;i*i<=n;i++)
        {
            if(arr[i]==true)
            {
                for(int j=i*2;j<=n; j+=i)
                {
                    arr[j]=false;
                }
            }
        }
        
        for(int i=2;i<=n;i++)
        {
            if(arr[i]==true)
            {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends