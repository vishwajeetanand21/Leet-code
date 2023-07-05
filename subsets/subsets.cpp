class Solution {
public:
    /*
    LOGIC: Generating all subset is as same as generating all sub-sequence of an array
           Therefore below is the code to generate all sub-sequence of an array
    */

    // Declare a global variable
    vector<vector<int>>finalAns; //variable to store all the possible combinations

    // the same function which use to generate all sub-sequence of an array
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