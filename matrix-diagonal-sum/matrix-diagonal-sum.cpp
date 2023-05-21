class Solution {
public:
    /*
    LOGIC: To find the principal diagonal element (i==j)
           To find the non-principal diagonal element (i+j==n-1) 
    */
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    sum+=mat[i][j];
                }
                else if(i+j==n-1)
                {
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
};