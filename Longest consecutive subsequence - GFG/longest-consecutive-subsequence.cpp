//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    // USING PRIORITY QUEUES
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
    return ans*/
    int findLongestConseqSubseq(int arr[], int n)
    {
        priority_queue<int, vector<int>, greater<int>>myQueue;
        
        for(int i=0;i<n;i++)
        {
            myQueue.push(arr[i]);
        }
        
        int ans=1;
        int temp=1;
        
        int currentElement=myQueue.top();
        myQueue.pop();
        
        while(myQueue.size())
        {
            int nextElement=myQueue.top();
            
            if(currentElement == nextElement)
            {
                myQueue.pop();
                continue;
            }
            if(currentElement+1 == nextElement)
            {
                temp++;
            }
            if(currentElement+1 != nextElement)
            {
                temp=1;
            }
            
            currentElement=myQueue.top();
            myQueue.pop();
            
            ans=max(ans, temp);
        }
        return ans;
    }
    
    /*Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
      
        //variable to store the answer
        int result=0;
      
        //making a set
        unordered_set<int>mySet;
        
        //adding all the elements in the set
        for(int i=0;i<n;i++) mySet.insert(arr[i]);
        
        
        //checking if (arr[i]-1) elements if present or not
        for(auto i: mySet)
        {
            if(mySet.find(i-1) == mySet.end())
            {
                // check where it break
                int j=1;
                while(mySet.find(i+j) != mySet.end())
                {
                    j++;
                }
                result=max(result, j);
            }
        }
        
        return result;
    }
    */
    
    
    
    /*
    LOGIC: BRUTE FORCE APPROACH
    We can simply sort the array and run a for loop to find the longest consecutive sequence.
    int findLongestConseqSubseq(int arr[], int n)
    {
        //Your code here
        if(n==0)
        {
            return 0;
        }
        
        sort(arr, arr+n);
        
        int prev=arr[0];
        int ans=1;
        int curr=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==prev+1)
            {
                curr++;
            }
            else if(arr[i]!=prev)
            {
                curr=1;
            }
            prev=arr[i];
            ans=max(ans, curr);
        }
        return ans;
    }
    */
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends