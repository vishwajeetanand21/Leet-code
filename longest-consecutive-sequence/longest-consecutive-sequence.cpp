class Solution {
public:
    int longestConsecutive(vector<int>& arr) 
    {
        int n=arr.size();

        if(n==0)
        {
            return 0;
        }
        

        sort(arr.begin(), arr.end());
    
        int ans = 1;
        int prev = arr[0];
        int cur = 1;
        
        for(int i = 1;i < arr.size();i++){
            if(arr[i] == prev+1){
                cur++;
            }   
            else if(arr[i] != prev){
                cur = 1;
            }
            prev = arr[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};