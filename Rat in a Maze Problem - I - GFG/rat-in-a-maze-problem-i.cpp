//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool isSafe(int currRow, int currCol, vector<vector<int>>&visited, vector<vector<int>>&matrix, int n)
    {
        if(currRow<n && currRow>=0 && currCol<n && currCol>=0)
        {
            if(visited[currRow][currCol]==0)
            {
                if(matrix[currRow][currCol]==1)
                {
                    return true;
                }
                // return false;
            }
            // return false;
        }
        return false;
    }
    void findPathHelper(int currRow, int currCol, vector<vector<int>>&matrix, int n, vector<string>&answer, string move, vector<vector<int>>&visited)
    {
        if(currRow==n-1 && currCol==n-1)
        {
            answer.push_back(move);
            return ;
        }
        
        // down
        if(isSafe(currRow+1, currCol, visited, matrix, n)==true)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow+1, currCol, matrix, n, answer, move+"D", visited);
            visited[currRow][currCol]=0;
        }
        
        // left
        if(isSafe(currRow, currCol-1, visited, matrix, n)==true)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow, currCol-1, matrix, n, answer, move+"L", visited);
            visited[currRow][currCol]=0;
        }
        
        // right
        if(isSafe(currRow, currCol+1, visited, matrix, n)==true)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow, currCol+1, matrix, n, answer, move+"R", visited);
            visited[currRow][currCol]=0;
        }
        
        // up
        if(isSafe(currRow-1, currCol, visited, matrix, n)==true)
        {
            visited[currRow][currCol]=1;
            findPathHelper(currRow-1, currCol, matrix, n, answer, move+"U", visited);
            visited[currRow][currCol]=0;
        }
    }
    vector<string> findPath(vector<vector<int>> &matrix, int n) 
    {
        vector<string>answer; //variable to store the path in a vector 
        
        if(matrix[0][0]==1)// only if the starting cell is 1, then only we can move to the next cell
        {
            vector<vector<int>>visited(n, vector<int>(n, 0));// a matrix which will keep a chech whether this cell has been visited to not 
            
            findPathHelper(0, 0, matrix, n, answer, "", visited);//calling the helper function 
        }
        
        return answer;//returning the final answer
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