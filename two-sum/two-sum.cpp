class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>answer;

        unordered_map<int, int>myMap;

        for(int i=0;i<nums.size();i++)
        {
            int currElement=nums[i];
            int moreNeeded=target-currElement;

            if(myMap.find(moreNeeded) != myMap.end())
            {
                answer.push_back(i);
                answer.push_back(myMap[moreNeeded]);
                return answer;
            }
            myMap[currElement]=i;
        }
        return answer;
    }


    /* This code will not work for this question
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());

        vector<int>ans;

        int left=0, right=nums.size()-1;

        while(left<right)
        {
            int sum=nums[left]+nums[right];

            if(sum==target)
            {
                ans.push_back(left);
                ans.push_back(right);
            }
            if(sum<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;        
    }
    */
    
    /*
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>answer;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    answer.push_back(i);
                    answer.push_back(j);
                }
            }
        }
        return answer;
    }*/
};