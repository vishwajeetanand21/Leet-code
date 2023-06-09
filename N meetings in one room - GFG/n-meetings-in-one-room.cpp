//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// STEP 1: 
class meeting
{
    public:
    int start;
    int end;
    int pos;
};
class Solution
{
    public:
    /*
    FOR ALL GREEDY PROBLEM
    STEP 1: Create a class or a structure according to the question, here is it start, end and posotion
    STEP 2: Create a STATIC comparator which will help to sort the array of a class
    STEP 3: Make an array of class and add all value in the array 
    STEP 4: Sort the array of class with the help of comparator
    STEP 5: Take care of the first meeting because that will be executed
    STEP 6: Start the loop from 1 to n because we have already taken care of the first meeting
    STEP 7: Finnaly return the answer
    */
    
    // STEP 2
    bool static comparator(meeting m1, meeting m2) //IMPORTANT: Always mention static while making comparator
    {
        // because we have to sort with respect to the ending time
        if(m1.end<m2.end)
            return true;
        else if(m1.end>m2.end)
            return false;
            
        // if both the ending time are same, then sort on the basis of position of the element
        else if(m1.pos<m2.pos)
            return true;
        else
            return false;
    }
    int maxMeetings(int starting[], int ending[], int n)
    {
        // STEP 3: Create an array of class
        meeting meet[n];
        // and store the starting time, ending time and positon(1-based indexing) in the array of classes
        for(int i=0;i<n;i++)
        {
            meet[i].start=starting[i];
            meet[i].end=ending[i];
            meet[i].pos=i+1;
        }
        
        // STEP 4: sort the array on the basis of ending time
        sort(meet, meet+n, comparator);
        
        // STEP 5: Handle the first element, because first meeting will definately happen
        int ans=1;//initially answer is 1 because we have handled the first element of the array 
        
        int limit=meet[0].end; //this variable will store the limit of the meetings
        
        // STEP 6: start the loop from 1 to n, because we have handled the first element
        for(int i=1;i<n;i++)
        {
            if(meet[i].start>limit)//if the starting time of the next meeting is more than 
            // the ending time of current meeting then only meeting will happen
            {
                limit=meet[i].end;//update the limit with the ending time of next meeting
                ans++;//increment the number of meetings
            }
        }
        
        // STEP 7: finally return the answer
        return ans;
    }
    
    /*
    int maxMeetings(int starting[], int ending[], int n)
    {
        vector<vector<int>>meet(n);
        for(int i=0;i<n;i++)
        {
            meet[i]={ending[i], starting[i], i+1};
        }
        
        sort(meet.begin(), meet.end());
        
        int limit=meet[0][0];
        int ans=1;
        
        for(int i=1;i<n;i++)
        {
            if(meet[i][1]>limit)
            {
                limit=meet[i][0];
                ans++;
            }
        }
        
        return ans;
    }*/
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends