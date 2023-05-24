class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>myMap;

        for(int i=0;i<nums.size();i++)
        {
            myMap[nums[i]]++;
        }

        int ans;
        int maxFrequency=INT_MIN;
        for(auto i: myMap)
        {
            if(i.second>maxFrequency)
            {
                maxFrequency=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};