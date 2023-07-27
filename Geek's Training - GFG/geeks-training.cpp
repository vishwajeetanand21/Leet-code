//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int usingTabulation(int n, vector<vector<int>>&points)
    {
        vector<vector<int>>dp(n, vector<int>(4,-1));
    
        // base case for day 0
        dp[0][0]=max(points[0][1], points[0][2]);
        dp[0][1]=max(points[0][0], points[0][2]);
        dp[0][2]=max(points[0][0], points[0][1]);
        dp[0][3]=max(points[0][0], max(points[0][1] , points[0][2]));
    
    
        for(int day=1; day<n; day++)
        {
            for(int lastDay=0; lastDay<4; lastDay++)
            {
                dp[day][lastDay]=0;
    
                int maxi=INT_MIN;
                for(int task=0; task<3; task++)
                {
                    if(task!=lastDay)
                    {
                        int temp=points[day][task] + dp[day-1][task];
                        maxi=max(maxi, temp);
                    }
                }
                dp[day][lastDay]=maxi;
            }
        }
        return dp[n-1][3];
    }  
  
    int usingMemoizationHelper(int day, int lastDay, vector<vector<int>>&points, vector<vector<int>>&dp)
    {
        if(dp[day][lastDay]!=-1)
        {
            return dp[day][lastDay];
        }
        
        // base case
        if(day==0)
        {
            int maxi=INT_MIN;
            for(int task=0; task<3;task++)
            {
                if(task!=lastDay)
                {
                    int temp=points[0][task];
                    maxi=max(maxi, temp);
                }
            }
            return maxi;
        }
        
        int maxi=INT_MIN;
        for(int task=0; task<3; task++)
        {
            if(task!=lastDay)
            {
                int temp=points[day][task] + usingMemoizationHelper(day-1, task, points, dp);
                maxi=max(temp, maxi);
            }
        }
        return dp[day][lastDay]=maxi;
    }
    int usingMemoization(int n, int lastDay, vector<vector<int>>&points)
    {
        vector<vector<int>>dp(n, vector<int>(4,-1));
        
        return usingMemoizationHelper(n-1, lastDay, points, dp);
    }
    
    int usingRecursion(int day, int lastDay,vector<vector<int>>&points)
    {
        // base condition
        if(day==0)
        {
            int maxi=INT_MIN;
            for(int task=0; task<3; task++)
            {
                if(task!=lastDay)
                {   
                    int temp=points[0][task];
                    maxi=max(maxi, temp);
                }
            }
            return maxi;
        }
        
        int maxi=INT_MIN;
        for(int task=0; task<3; task++)
        {
            if(task!=lastDay)
            {
                int temp=points[day][task] + usingRecursion(day-1, task, points);
                maxi=max(maxi, temp);
            }
        }
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) 
    {
        // Code here
        // return usingRecursion(n-1, 3, points);
        // return usingMemoization(n, 3, points);
        return usingTabulation(n, points);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends