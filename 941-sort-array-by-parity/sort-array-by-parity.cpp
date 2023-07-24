class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) 
    {
        for (int i = 0, j = 0; j < arr.size(); j++)
            if ( (arr[j]&1) == 0) //even element
            {
                swap(arr[i], arr[j]);
                i++;
            }
        return arr;
    }
};