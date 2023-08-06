//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int amount)
    {
        // code here
        int arr[]={2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int n=10;
        
        
        vector<int>answer;
        for(int i=0;i<10; i++)
        {
            if(amount<=0)
            {
                break;
            }
            
            int currentDenomination=arr[i];
            while(amount >= currentDenomination)
            {
                amount -= currentDenomination;
                answer.push_back(currentDenomination);
            }
        }
        
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends