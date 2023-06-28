//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > array, int n, int m) {
	    // code here
	    int rows = array.size();
        int cols = array[0].size();
        
        int row = 0;
        int col = cols - 1;
        
        int max_count = 0;
        int max_index = -1;
        
        while (row < rows && col >= 0) {
            if (array[row][col] == 1) {
                max_count = col + 1;
                max_index = row;
                col--;
            } else {
                row++;
            }
        }
        
        return max_index;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends