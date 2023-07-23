class Solution {
public:
    int xorOperation(int n, int start) 
    {
        int ans=0;

        vector<int>arr;
        
        for(int i=0; i<n;i++)
        {
            // int temp=start+2*i;
            // arr.push_back(temp);
            ans^=(start+2*i);
        }

        /*int ans=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            ans^=arr[i];
        }*/

        return ans;
    }
};