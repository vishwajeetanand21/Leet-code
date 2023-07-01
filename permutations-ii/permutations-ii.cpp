class Solution {
public:
    void recurPermute(int index, vector < int > & nums, set< vector < int >> & ans) {
        if (index == nums.size()) //whenever the index reaches n it means we got one solution
        {
            ans.insert(nums);//add the solution to the answer vector
            return; 
        }
        for (int i = index; i < nums.size(); i++) //traverse from left to right
        {
            swap(nums[index], nums[i]); //and swap the index element and ith element
            recurPermute(index + 1, nums, ans); //call the recursive function again
            swap(nums[index], nums[i]); //backtracking line
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& arr)
    {
        set < vector < int >> ans;//vector to store all the possible permutations
        recurPermute(0, arr, ans); //calling the recursive function
    //   return ans; //finally returning the answer 
        vector<vector<int>>finalAns;

        for(auto i: ans)
        {
            finalAns.push_back(i);
        }
        return finalAns;
    }
    /*void solve(vector<int>& arr, vector<int>& curr, vector<bool>& visited, vector<vector<int>>& answer)
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
    }*/
};