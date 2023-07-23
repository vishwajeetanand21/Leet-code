class Solution {
public:
    int xorOperation(int n, int start) 
    {
        int ans=0;

        // DON'T CREATE AN EXTRA ARRAY TO STORE THE ELEMENTS AND THEN PERFORM XOR OPERATION
        // vector<int>arr;
        
        for(int i=0; i<n;i++)
        {
            // int temp=start+2*i;
            // arr.push_back(temp);
            
            ans^=(start+2*i); //PERFORM THE XOR OPERATION HERE INSTEAD
        }

        /*int ans=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            ans^=arr[i];
        }*/

        return ans;
    }
};