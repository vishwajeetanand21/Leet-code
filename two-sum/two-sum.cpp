class Solution 
{
    public:
    /*
    LOGIC: we will store the ELEMENT along will its INDEX in the HashMap.
           Then we will traverse the array from left to right
           We'll store the current element as currElement
           And we'll calculate how much more is needed as moreNeeded
                if moreNeeded is already in our map
                    then simply return the index of current element and the index of moreNeeded element
                else
                    simply store the current element and it's index 
    */
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>answer; //vector to store the answer

        unordered_map<int, int>myMap; //map to store the element ans it's index

        for(int i=0;i<nums.size();i++)//loop to traverse the array
        {
            int currElement=nums[i]; //current element
            int moreNeeded=target-currElement; //how much more is needed

            if(myMap.find(moreNeeded) != myMap.end()) //if how much more needed is already present in our map
            {
                answer.push_back(i); //then simply return current element index
                answer.push_back(myMap[moreNeeded]); //and the index of more needed element
                return answer;
            }
            myMap[currElement]=i; //if not then add the new element and store it's index
        }
        return answer;//finally return the answer
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