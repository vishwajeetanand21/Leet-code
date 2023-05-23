//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    /*
    LOGIC:
    STEP 1: Take input of all pairs in a vector and sort the vector
    STEP 2: Create a stack which will contain pairs
    STEP 3: Put the first element of vector into the stack
    STEP 4: Start the loop from 1: for(int i=1;i<n;i++)
            Why 1?-> because we have already put the first element into the stack
    STEP 5: Maintain 4 variables
            start1= stack.top().first
            end1= stack.top().second
            start2= vector[i].first
            end2= vector[i].second
    STEP 6: To the following operation as follows:
            if(end1<start2)
                push(start2, end2) in the stack
            else
                pop the stack
                end1=max(end1, end2)
                push(start1, end1) in the stack
    STEP 7: Create an answer vector, to push all stack element into that vector
    STEP 8: Return that vector
    */
    vector<vector<int>> overlappedInterval(vector<vector<int>>& myVector) 
    {
        // Code here
        // step 1
        sort(myVector.begin(),myVector.end());
        
        // step 2
        stack<pair<int,int>>myStack;
        
        // step 3
        myStack.push({myVector[0][0],myVector[0][1]});
        
        // step 4
        for(int i=1;i<myVector.size();i++)
        {
            // step 5
            //[a,b][c,d]
            int start1=myStack.top().first; //a
            int end1=myStack.top().second; //b
            int start2=myVector[i][0];  //c
            int end2=myVector[i][1];  //d
            
            // step 6: 
            // [8,10][15,18]: Here b=10 and c=15, there is a gap between c and b. Therefor we have to push the 
            // current element into the stack
            if(end1<start2) //b<c
            {
                myStack.push({start2,end2});
            }
            else 
            // [1,3][2,6]: Here b=3 and c=2, there is no gap between c and b. Therefore we will merge this interval
            {
                myStack.pop(); //first we will pop out the current top from that stack
                end1=max(end1,end2); //then we will update the new end
                myStack.push({start1,end1}); //Then finally push the new interval into the stack
            }
        }
        
        // step 7: Transfer all the element from stack to vector
        vector<vector<int>>answer;
        while(myStack.size()!=0)
        {
            answer.push_back({myStack.top().first,myStack.top().second});
            myStack.pop();
        }
        
        //the expected output is in reverse order, therefore we have to reverse our answer
        reverse(answer.begin(), answer.end());

        // step 8: Return the answer vector
        return answer;         
    }
};

//{ Driver Code Starts.
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
}
// } Driver Code Ends