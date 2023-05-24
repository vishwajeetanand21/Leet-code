class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        int mini=n/3;

        unordered_map<int, int>myMap;

        for(int i=0;i<n;i++)
        {
            myMap[arr[i]]++;
        }

        vector<int>answer;

        for(auto i: myMap)
        {
            if(i.second>mini)
            {
                answer.push_back(i.first);
            }
        }

        return answer;
    }
};