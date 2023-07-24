class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) 
    {
        // map<int, int>myMap;

        for(int i=0;i<arr.size();i++)
        {
            arr[i]= arr[i]*arr[i];
        }

        sort(arr.begin(), arr.end());

        return arr;
    }
};