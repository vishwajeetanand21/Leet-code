class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        
        int rows[m];
        for(int i=0;i<m;i++) rows[i]=0;
        int cols[n];
        for(int j=0;j<n;j++) cols[j]=0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(arr[i][j]==0)
                {
                    rows[i]=1;
                    cols[j]=1;
                }
            }
        }

        // modifying the array
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rows[i]==1 || cols[j]==1)
                {
                    arr[i][j]=0;
                }
            }
        }

    }
};