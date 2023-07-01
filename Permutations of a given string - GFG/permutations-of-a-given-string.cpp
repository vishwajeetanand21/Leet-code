//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
        void recurPermute(int index, string&nums, vector<string>&ans) 
        {
            if (index == nums.size()) 
            {
                ans.push_back(nums);
                return;
            }
            
            for (int i = index; i < nums.size(); i++) 
            {
                swap(nums[index], nums[i]);
                recurPermute(index + 1, nums, ans);
                swap(nums[index], nums[i]);
            }
        }
		vector<string>find_permutation(string nums)
		{
		    // Code here there
		    vector <string> ans;
            recurPermute(0, nums, ans);
            
            
            // the below code is for getting unique strings in the final answer
            set<string>uniqueAns;
            for(int i=0;i<ans.size();i++)
            {
                uniqueAns.insert(ans[i]);
            }
            
            vector<string>finalAns;
            for(auto &i: uniqueAns)
            {
                finalAns.push_back(i);
            }
            return finalAns;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends