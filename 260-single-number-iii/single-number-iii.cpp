class Solution {
public:
    vector<int> singleNumber(vector<int>& arr) 
    {
        int n=arr.size();
        
        unordered_map<int, int>myMap;
    
        for(int i=0;i<n;i++)
        {
            myMap[arr[i]]++;
        }
        
        vector<int>ans;
        for(auto i:myMap)
        {
            if(i.second==1)
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;    
    }
};