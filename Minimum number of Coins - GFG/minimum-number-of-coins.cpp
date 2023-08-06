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
        
        // array of denominations
        int arr[]={2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        // array size
        int n=10;
        
        // vector to store the answer
        vector<int>answer;
        
        // traversing the array of denominatios TC: O(10) which is equivalent to O(1)
        for(int i=0;i<10; i++)
        {
            if(amount<=0) //whenever the amount reaches to 0 or negative then break the loop
            {
                break;
            }
            
            // current coin
            int currentDenomination=arr[i];
            
            // there is a infinite supply of each denomination that's why there is a while loop
            // which will run untill the amount >= current coin
            while(amount >= currentDenomination)
            {
                amount -= currentDenomination; //keep on updating the amount
                answer.push_back(currentDenomination);// add that coin into the array
            }
        }
        
        // finally return the array
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