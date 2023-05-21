//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int DiagonalSum(vector<vector<int> >& arr) {
        // Code here
        int n=arr.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i==j)
                {
                    sum+=arr[i][j];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i+j==n-1)
                {
                    sum+=arr[i][j];
                }
            }
        }
        return sum;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.DiagonalSum(matrix);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends