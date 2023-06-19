//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*
    STEP 1: First we will sort the array in increasing order
    STEP 2: Then we will maintain a window of M(5 in this case)
    STEP 3: We'll calculate the difference of maximum element and minimum element in that window
    STEP 4: We'll traverse from left to right untill we reach to the last element
    STEP 5: Finally we'll return the window with minimum difference
    
    DRY RUN: 
    
    (1 3 4 7 9) 9 12 56     9-1=8
    1 (3 4 7 9 9) 12 56     9-3=6
    1 3 (4 7 9 9 12) 56     12-4=8
    1 3 4 (7 9 9 12 56)     56-7=49
    
    Therefore the answer is: 6 minimum of all difference
    */
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        //STEP 1:
        sort(a.begin(), a.end());
        
        long long ans=INT_MAX;
        
        long long i=0,j=m-1;
        
        while(j<n)
        {
            ans=min(a[j]-a[i] , ans);
            i++;
            j++;
        }
        
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends