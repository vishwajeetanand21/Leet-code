class Solution {
public:
    /*
    OPTIMAL SOLUTION: USING PRIORITY QUEUE

    Step 1: Create a priority queue and add all the array elements in the queue

    Step 2: Maintain 3 variables
                answer: to store the maximum sequence
                temp:   to store the current streak
                currentElement: it will store the current element of the queue

    Step 3: Now traverse in the queue from second element to the last element
                if currentElement==nextElement (this means duplication)
                    continue; simply ignore, don't do anything
                
                if the currentElement+1 == nextElement
                    temp+=1
                else
                    temp=1
                pop the current element from the queue 
                ans=max(ans, temp)

    Step 4: Return the answer
    
    DRY RUN
    arr=   [1, 2, 0, 1]
    pQueue=[0, 1, 1, 2]

    currenetElement = pQueue.top() = 0
    ans=1
    temp=1

    traverse from 2nd element to the last element
            if currenetElement==nextElement
                continue
            if currentElement+1==nextElement
                temp+=1
            if currentElement!=nextElement
                temp=1
            
            currentElement=pQueue.top()
            pQueue.pop()
            ans=max(ans, temp)
    return ans
    */
    int longestConsecutive(vector<int>& arr)
    {
        int n=arr.size();

        if(n==0)
        {
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>>myQueue;

        for(int i=0;i<n;i++) //push all the elements in the queue
        {
            myQueue.push(arr[i]);
        }

        int ans=1;
        int temp=1;

        int currentElement=myQueue.top();
        myQueue.pop();

        while(myQueue.size()!=0)
        {
            if(currentElement == myQueue.top()) //IMPORTANT
            {
                myQueue.pop();
                continue;
            }

            if(currentElement+1 == myQueue.top())
            {
                temp += 1;
            }
            if(currentElement+1 != myQueue.top())
            {
                temp = 1;
            }

            currentElement=myQueue.top();
            myQueue.pop();

            ans=max(ans, temp);
        }
        return ans;
    }

    /*
    LOGIC: BRUTE FORCE 
    We can simply sort the array and run a for loop to find the longest consecutive sequence.
    
    int longestConsecutive(vector<int>& arr) 
    {
        int n=arr.size();

        if(n==0)
        {
            return 0;
        }
        

        sort(arr.begin(), arr.end());
    
        int ans = 1;
        int prev = arr[0];
        int cur = 1;
        
        for(int i = 1;i < arr.size();i++){
            if(arr[i] == prev+1){
                cur++;
            }   
            else if(arr[i] != prev){
                cur = 1;
            }
            prev = arr[i];
            ans = max(ans, cur);
        }
        return ans;
    }
    */
};