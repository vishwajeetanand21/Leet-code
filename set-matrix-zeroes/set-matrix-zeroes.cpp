class Solution {
public:
    /*
    [[1,1,1],
     [1,0,1],
     [1,1,1]]
    LOGIC: we will maintain two arrays rows[m]={0} and cols[n]={0}
    then we'll traverse the matrix and if we encounter any 0 then rows[i]=1 and cols[j]=1
    at this point of time rows=[0,1,0] and cols=[0,1,0]
    then again we will traverse the matrix
    if (rows[i]==1 or cols[j]==1) then arr[i][j]=0 
    */
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