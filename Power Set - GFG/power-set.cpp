//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    /*
	    LOGIC: The power set is as same as subset and sub-sequence for any array
	           Therefore we will be writing the code for generating all the sub-sequence of an array
	    */
	
	    // Declare a global variable to store all the combinations
	    vector<string>finalAns;
	    
	    //write the same code for generating all the sub-sequence of any string
	    // Slight modification here use a string instead of a vector
	    void solve(int index, string answer, string str, int n)
	    {
	        if(index==n)
	        {
                finalAns.push_back(answer);
	            return;
	        }
	        
	        answer+=str[index];
	        solve(index+1, answer, str, n);
	        
	        answer.pop_back();
	        solve(index+1, answer, str, n);
	    }
		vector<string> AllPossibleStrings(string str){
		    // Code here
		    int n=str.size();
		    
		    string answer="";
		    
		    solve(0, answer, str, n);
		    
		    sort(finalAns.begin(), finalAns.end());
		    
		    finalAns.erase(finalAns.begin());// IMPORTANT: Removing the empty string "" from the vector
		    
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