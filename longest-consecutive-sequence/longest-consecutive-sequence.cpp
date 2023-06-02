class Solution {
public:
    int longestConsecutive(vector<int>& arr)
    {
        int n=arr.size();

        if(n==0)
        {
            return 0;
        }

        priority_queue<int, vector<int>, greater<int>>myQueue;

        for(int i=0;i<n;i++)
        {
            myQueue.push(arr[i]);
        }

        int ans=1;
        int temp=1;

        int currentElement=myQueue.top();
        myQueue.pop();

        while(myQueue.size()!=0)
        {
            if(currentElement == myQueue.top())
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