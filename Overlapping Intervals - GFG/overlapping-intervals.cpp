// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& myVector) 
    {
        sort(myVector.begin(),myVector.end());
        
        stack<pair<int,int>>myStack;
        myStack.push({myVector[0][0],myVector[0][1]});
        
        for(int i=1;i<myVector.size();i++)
        {
            int start1=myStack.top().first;
            int end1=myStack.top().second;
            int start2=myVector[i][0];
            int end2=myVector[i][1];
            
            if(end1<start2)
            {
                myStack.push({start2,end2});
            }
            else
            {
                myStack.pop();
                end1=max(end1,end2);
                myStack.push({start1,end1});
            }
        }
        vector<vector<int>>answer;
        while(myStack.size()!=0)
        {
            answer.push_back({myStack.top().first , myStack.top().second});
            myStack.pop();
        }
        
        reverse(answer.begin(), answer.end());
        return answer;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends