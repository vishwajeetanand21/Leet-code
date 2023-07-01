class Solution {
public:
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
        if (index == nums.size()) //whenever the index reaches n it means we got one solution
        {
            ans.push_back(nums);//add the solution to the answer vector
            return; 
        }
        for (int i = index; i < nums.size(); i++) //traverse from left to right
        {
            swap(nums[index], nums[i]); //and swap the index element and ith element
            recurPermute(index + 1, nums, ans); //call the recursive function again
            swap(nums[index], nums[i]); //backtracking line
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
      vector < vector < int >> ans;//vector to store all the possible permutations
      recurPermute(0, nums, ans); //calling the recursive function
      return ans; //finally returning the answer
    }
};