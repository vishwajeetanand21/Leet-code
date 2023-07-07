//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void findPathHelper(int currRow, int currCol, vector<vector<int>>&mat, int n, vector<string>&ans, string move, vector<vector<int>>&visited)
    {
        if(currRow==n-1 && currCol==n-1)
        {
            ans.push_back(move);
            return ;
        }
        
        // downward
        if(currRow+1<n    &&   visited[currRow+1][currCol]==0     &&      mat[currRow+1][currCol]==1)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow+1, currCol, mat, n, ans, move+"D", visited);
            visited[currRow][currCol]=0;//backtracking line 
        }
        
        // left
        if(currCol-1>=0   &&   visited[currRow][currCol-1]==0     &&      mat[currRow][currCol-1]==1)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow, currCol-1, mat, n, ans, move+"L", visited);
            visited[currRow][currCol]=0;
        }
        
        // right
        if(currCol+1<n    &&   visited[currRow][currCol+1]==0     &&      mat[currRow][currCol+1]==1)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow, currCol+1, mat, n, ans, move+"R", visited);
            visited[currRow][currCol]=0;
        }
        
        // upward
        if(currRow-1>=0   &&   visited[currRow-1][currCol]==0     &&      mat[currRow-1][currCol]==1)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow-1, currCol, mat, n, ans, move+"U", visited);
            visited[currRow][currCol]=0;
        }
    }  
    vector<string> findPath(vector<vector<int>> &mat, int n) 
    {
        // Your code goes here
            
        // declaring a vector to store all the possible paths
        vector<string>ans;
        vector<vector<int>>visited(n, vector<int>(n,0));
        
        if (mat[0][0] == 1) 
        {
            findPathHelper(0, 0, mat, n, ans, "", visited);
        }
       
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends