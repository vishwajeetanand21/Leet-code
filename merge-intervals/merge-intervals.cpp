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
    vector<vector<int>> merge(vector<vector<int>>& myVector) 
    {
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
            int start1=myStack.top().first;
            int end1=myStack.top().second;
            int start2=myVector[i][0];
            int end2=myVector[i][1];
            
            // step 6
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
        
        // step 7
        vector<vector<int>>answer;
        while(myStack.size()!=0)
        {
            answer.push_back({myStack.top().first,myStack.top().second});
            myStack.pop();
        }

        // step 8
        return answer;
    }
};