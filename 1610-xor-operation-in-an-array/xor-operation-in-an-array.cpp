class Solution {
public:
    int xorOperation(int n, int start) 
    {
        vector<int>arr;
        
        for(int i=0; i<n;i++)
        {
            int temp=start+2*i;
            arr.push_back(temp);
        }

        int ans=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            ans^=arr[i];
        }

        return ans;
    }
};