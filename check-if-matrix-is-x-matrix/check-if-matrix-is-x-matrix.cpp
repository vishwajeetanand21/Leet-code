class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& arr) 
    {
        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // principle diagonal
                if(i==j)
                {
                    if(arr[i][j]==0)
                    {
                        return false;
                    }
                }

                // non-principle diagonal
                if(i+j==n-1)
                {
                    if(arr[i][j]==0)
                    {
                        return false;
                    }
                }

                if(i!=j && (i+j)!=n-1)
                {
                    if(arr[i][j]!=0)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};