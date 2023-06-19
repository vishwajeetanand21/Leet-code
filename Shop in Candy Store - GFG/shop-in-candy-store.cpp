//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    /*
    LOGIC: 
    STEP 1: Sort the array in ascending order
    STEP 2: For minimum cost
            Select 1 candy from the starting of the array 
            Select k candies from the ending of the array
            Update the index according to this
            calculate the sum of buying all the candies
    
    STEP 3: For maximum cost
            Select 1 candy from the ending of the array
            Select k candies from the starting of the array
            Update the index according to this
            calculate the sum of buying all the candies
            
    STEP 4: Finally add the minimum cost and maximum cost in a vector and return it.
    
    */
    vector<int> candyStore(int candies[], int n, int k)
    {
        // FOR LOGIC REFER TO LOVE BABBAR'S GREEDY IN ONE VIDEO
        
        // first sort the array 
        sort(candies, candies+n);
        
        // for minimum amount of money
        int minCost=0;
        int buy=0, free=n-1;
        while(buy<=free)
        {
            minCost += candies[buy];
            buy++;
            
            free=free-k;
        }
        
        // for masimum amount of money
        int maxCost=0;
        buy=n-1, free=0;
        while(free<=buy)
        {
            maxCost += candies[buy];
            buy--;
            
            free=free+k;
        }
        
        vector<int>ans;
        ans.push_back(minCost);
        ans.push_back(maxCost);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends