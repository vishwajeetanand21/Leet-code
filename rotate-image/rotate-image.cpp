class Solution {
public:
    /*
    LOGIC: First do the transpose of the matrix
           Then reverse each row of the matrix
    */
    void transposeMatrix(vector<vector<int>>& arr, int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
    }
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();

        transposeMatrix(arr, n);

        for(int i=0;i<n;i++)
        {
            reverse(arr[i].begin(), arr[i].end());
        }
    }
};