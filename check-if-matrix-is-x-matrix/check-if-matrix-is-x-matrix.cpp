class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& arr) 
    {
        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // principle diagonal elements should not be 0
                if(i==j)
                {
                    if(arr[i][j]==0)
                    {
                        return false;
                    }
                }

                // second diagonal element also should not be 0 
                if(i+j==n-1)
                {
                    if(arr[i][j]==0)
                    {
                        return false;
                    }
                }

                // other than diagonal elements all the elements should be 0
                if(i!=j && (i+j)!=n-1)
                {
                    if(arr[i][j]!=0)
                    {
                        return false;
                    }
                }
            }
        }
        // if all these condition met then we can say that the given matrix is a x-matrix
        return true;
    }
};