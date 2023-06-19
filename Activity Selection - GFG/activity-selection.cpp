//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class activity
{
    public:
    int start;
    int end;
    int pos;
};
class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    bool static comparator(activity a1, activity a2)
    {
        if(a1.end<a2.end)
            return true;
        else if(a1.end>a2.end)
            return false;
        else if(a1.pos<a2.pos)
            return true;
        else
            return false;
    }
    int activitySelection(vector<int> starting, vector<int> ending, int n)
    {
        activity job[n];
        for(int i=0;i<n;i++)
        {
            job[i].start=starting[i];
            job[i].end=ending[i];
            job[i].pos=i+1;
        }
        
        sort(job, job+n, comparator);
        
        int limit=job[0].end;
        int ans=1;
        
        for(int i=1;i<n;i++)
        {
            if(job[i].start>limit)
            {
                limit=job[i].end;
                ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}

// } Driver Code Ends