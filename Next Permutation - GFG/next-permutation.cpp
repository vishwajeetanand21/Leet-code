//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // METHOD 2: using inbuilt stl next_permutation library in c++
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        next_permutation(arr.begin(), arr.end());
        return arr;
    }
    /*METHOD 1:
    vector<int> nextPermutation(int n, vector<int> arr)
    {
        int idx=-1;
        //n=arr.size();
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]>arr[i-1])
            {
                idx=i;
                break;
            }
        }
        if(idx==-1)
        {
            reverse(arr.begin(),arr.end());
        }
        else
        {
            int prev=idx;
            for(int i=idx+1;i<n;i++)
            {
                if(arr[i]>arr[idx-1] && arr[i]<=arr[prev])
                {
                    prev=i;
                }
            }
            swap(arr[idx-1],arr[prev]);
            reverse(arr.begin()+idx, arr.end());
        }
        return arr;
    }
    */
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends