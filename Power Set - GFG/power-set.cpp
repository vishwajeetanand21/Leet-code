//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
        void solve(int currIndex, vector<string>& finalAns, string& answer, const string& str, int n)
        {
            if (currIndex == n)
            {
                finalAns.push_back(answer);
                return;
            }
        
            // pick
            answer.push_back(str[currIndex]);
            solve(currIndex + 1, finalAns, answer, str, n);
        
            // not pick
            answer.pop_back();
            solve(currIndex + 1, finalAns, answer, str, n);
        }
        
        vector<string> AllPossibleStrings(string str)
        {
            int n = str.size();
            
            vector<string> finalAns;
            
            string answer = "";
            
            solve(0, finalAns, answer, str, n);
            
            sort(finalAns.begin(), finalAns.end());
            
            finalAns.erase(finalAns.begin());// removing the blank space from the front
            
            return finalAns;
        }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends