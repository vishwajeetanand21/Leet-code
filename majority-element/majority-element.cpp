class Solution {
public:
    int majorityElement(vector<int>&arr)
    {
        int n=arr.size();
        int i, candidate = -1, votes = 0;
        // Finding majority candidate
        for (i = 0; i < n; i++) {
            if (votes == 0) {
                candidate = arr[i];
                votes = 1;
            }
            else {
                if (arr[i] == candidate)
                    votes++;
                else
                    votes--;
            }
        }
        int count = 0;
        // Checking if majority candidate occurs more than n/2
        // times
        for (i = 0; i < n; i++) {
            if (arr[i] == candidate)
                count++;
        }
    
        if (count > n / 2)
            return candidate;
        return -1;
    }
    /*METHOD 1: Brute Force Method
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
    }*/
};