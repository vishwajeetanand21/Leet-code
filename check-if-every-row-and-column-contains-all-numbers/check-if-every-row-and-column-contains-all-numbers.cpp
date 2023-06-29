class Solution {
public:
    bool checkValid(vector<vector<int>>& arr) 
    {
        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            set<int>mySet1, mySet2;
            
            for(int j=0;j<n;j++)
            {
                mySet1.insert(arr[i][j]);
                mySet2.insert(arr[j][i]);
            }

            if(mySet1.size()!=n || mySet2.size()!=n)
            {
                return false;
            }
        }

        return true;
    }
};