//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int currIndex, vector<vector<int>>&finalAns, vector<int>&answer, vector<int>&arr, int n)
    {
        if(currIndex==n)
        {
            finalAns.push_back(answer);
            return;
        }
        
        // pick
        answer.push_back(arr[currIndex]);
        solve(currIndex+1, finalAns, answer, arr, n);
        
        // not pick
        answer.pop_back();
        solve(currIndex+1, finalAns, answer, arr, n);
    }
    vector<vector<int>> subsets(vector<int>& arr)
    {
        int n=arr.size();
        
        vector<vector<int>>finalAns;
        
        vector<int>answer;
        
        solve(0, finalAns, answer, arr, n);
        
        sort(finalAns.begin(), finalAns.end());
        
        return finalAns;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends