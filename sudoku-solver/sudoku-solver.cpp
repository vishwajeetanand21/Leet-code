class Solution {
public:
    bool isvalid(vector<vector<char>>& arr,int currRow,int currCol,char digit)
    {
        // current row
        for(int i=0;i<9;i++)
        {
            if(arr[currRow][i]==digit)
            {
                return false;
            }
        }

        // current column
        for(int i=0;i<9;i++)
        {
            if(arr[i][currCol]==digit)
            {
                return false;
            }
        }
         
        // current grid
        int x=(currRow/3)*3;
        int y=(currCol/3)*3;

        for(int i=x;i<x+3;i++)
        {
            for(int j=y;j<y+3;j++)
            {
                if(arr[i][j]==digit)
                {
                    return false;
                }
            }
        }

        // finally return true
        return true;
    }
    bool solve(vector<vector<char>>& arr) 
    {
       for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(arr[i][j]=='.')
                {
                    for(char digit='1';digit<='9';digit++)
                    {
                        if(isvalid(arr,i,j,digit))
                        {
                            arr[i][j]=digit;
                            if(solve(arr))
                                return true;
                            arr[i][j]='.';//backtracking
                        }
                    }
                    return false;
                }
            }
        }
       return true;
    }
    void solveSudoku(vector<vector<char>>& arr) 
    {
        solve(arr);    
    }
};