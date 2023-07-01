class Solution {
public:
    void solve(vector<int>& arr, vector<int>& curr, vector<bool>& visited, vector<vector<int>>& answer)
    {
        if (curr.size() == arr.size())
        {
            answer.push_back(curr);
            return;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            if (!visited[i])
            {
                // Avoid duplicate permutations
                if (i > 0 && arr[i] == arr[i - 1] && !visited[i - 1])
                    continue;

                curr.push_back(arr[i]);
                visited[i] = true;

                solve(arr, curr, visited, answer);

                curr.pop_back();
                visited[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& arr) {
        sort(arr.begin(), arr.end());  // Sort the input to handle duplicates
        vector<vector<int>> answer;
        vector<int> curr;
        vector<bool> visited(arr.size(), false);

        solve(arr, curr, visited, answer);

        return answer;
    }
};