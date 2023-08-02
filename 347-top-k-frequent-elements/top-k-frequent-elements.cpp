class Solution {
public:
    vector<int> topKFrequent(vector<int>& arr, int k) 
    {
        int n=arr.size();

        unordered_map<int, int>myMap;
        for(int i=0;i<n;i++)
        {
            myMap[arr[i]]++;
        }

        priority_queue<pair<int, int>>myQueue;

        for(auto i: myMap)
        {
            myQueue.push({i.second, i.first}); //important setp
        }

        vector<int>answer;

        while(k>0)
        {
            answer.push_back(myQueue.top(). second);
            myQueue.pop();
            k--;
        }

        return answer;
    }
};