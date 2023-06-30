//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isSafe(vector<vector<int>>&board, int currRow, int currCol, int n)
    {
        // storing the value of current row and column
        int originalRow=currRow;
        int originalCol=currCol;
    
        // finding in principle diagonal (↖)
        while(currRow>=0 && currCol>=0)
        {
            if(board[currRow][currCol]==1)
            {
                return false;
            }
            currRow--;
            currCol--;
        }
    
        // finding in left-side of the current row (←)
        currRow=originalRow;
        currCol=originalCol;
        while(currCol>=0)
        {
            if(board[currRow][currCol]==1)
            {
                return false;
            }
            currCol--;
        }
    
        // findding in the anti diagonal (↙)
        currRow=originalRow;
        currCol=originalCol;
        while(currRow<n && currCol>=0)
        {
            if(board[currRow][currCol]==1)
            {
                return false;
            }
            currRow++;
            currCol--;
        }
    
        // finally return true, because it is safe to place a queen here
        return true;
    }    
    void solve(int currCol, vector<vector<int>>&answer, vector<vector<int>>&board, int n)
    {
        // if the current column reaches n then it means we have successfull placed all the queen in the right way
        if(currCol==n) 
        {
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==1)
                    {
                        temp.push_back(j+1);//we have to store the column number where the queen stands
                        break;
                    }
                }
            }
            answer.push_back(temp);
            sort(answer.begin(), answer.end()); //IMPORTANT: the resultant answer should be in sorted order
        }
        
        // We will be moving from top to bottom in each row to place a queen
        // and if we place a queen in 1 row we will call the recursive function to the next column        
        for(int currRow=0; currRow<n;currRow++)
        {
            if(isSafe(board, currRow, currCol, n)==true)//check is it safe to place the queen in this position
            {
                board[currRow][currCol]=1;//if is it safe to put the queen
                solve(currCol+1, answer, board, n);//and call the recursive call in the next column
                board[currRow][currCol]=0;//backtracking line
            }
        }
    }
    vector<vector<int>> nQueen(int n) 
    {
        // code here
        vector<vector<int>>answer; //overall answer variable which will store all the answer strings
        
        vector<vector<int>>board;//variable to store the order of one board
        
        // initializing the board with all zeros 
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int i=0;i<n;i++)
            {
                temp.push_back(0);
            }
            board.push_back(temp);
        }
        
        // calling a recursive function
        solve(0, answer, board, n);
        
        // returning the answer
        return answer;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends