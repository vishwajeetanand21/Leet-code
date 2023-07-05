class Solution {
public:
    vector<vector<int>>finalAns;

    void solve(int index, vector<int>&answer, vector<int>&arr, int n)
    {
        if(index==n)
        {
            finalAns.push_back(answer);
            return ;
        }

        // pick
        answer.push_back(arr[index]);
        solve(index+1, answer, arr, n);

        // not pick
        answer.pop_back();
        solve(index+1, answer, arr, n);
    }
    vector<vector<int>> subsets(vector<int>& arr) 
    {
        int n=arr.size();

        vector<int>answer;

        solve(0, answer, arr, n);

        return finalAns;
    }
};