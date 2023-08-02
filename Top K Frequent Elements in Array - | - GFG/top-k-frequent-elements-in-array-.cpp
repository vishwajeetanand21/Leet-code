//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& arr, int k) 
    {
        // Code here
        int n=arr.size();

        unordered_map<int, int>myMap;
        for(int i=0;i<n;i++)
        {
            myMap[arr[i]]++;
        }

        priority_queue<pair<int, int>>myQueue;

        for(auto i: myMap)
        {
            myQueue.push({i.second, i.first}); //important setp
        }

        vector<int>answer;

        while(k>0)
        {
            answer.push_back(myQueue.top(). second);
            myQueue.pop();
            k--;
        }

        return answer;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends