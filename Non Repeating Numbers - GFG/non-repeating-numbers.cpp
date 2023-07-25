//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*
    LOGIC: 
        STEP 1: Find the xor of all the elements
                1^2^3^2^1^4
                3^4
         xorAll=7
        
        SETP 2: Find the position of the right most set bit of xorAll
                xorAll=7
                      =1 1 (1)
                at 0th index there is a set bit
                or the position of the right most set bit of xorAll is 0th index
        
        STEP 3: Group the elements of the array into two groups
                If the right most bit of xorAll is same as element's bit-> groupA
                Otherwise-> groupB
                
                1: 0 0 (1)->groupA
                2: 0 1 (0)->groupB
                3: 0 1 (1)->groupA
                2: 0 1 (0)->groupB
                1: 0 0 (1)->groupA
                4: 1 0 (0)->groupB
                
        STEP 4: Take the xor of both the group
                groupA= 1^3^1 =3 
                groupB= 2^2^4 =4
        
        STEP 5: Return these two elements
    */
    int rightMostSetBit(int n)
    {
        int count=1;
        while(n>0)
        {
            if(n&1==1)
            {
                break;
            }
            n=n>>1;
            count++;
        }
        return count;
    }
    vector<int> singleNumber(vector<int> arr) 
    {
        // STEP 1:
        int xorAll=0;
        for(int i=0; i<arr.size();i++)
        {
            xorAll^=arr[i];
        }
        
        // STEP 2:
        int setbit=xorAll & (~(xorAll-1));
        // int setbit=rightMostSetBit(xorAll);
        
        // SETP 3:
        int groupA=0, groupB=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]&setbit)
            {
                groupA^=arr[i];
            }
            else
            {
                groupB^=arr[i];
            }
        }
        
        // STEP 4
        vector<int>ans;
        ans.push_back(groupA);
        ans.push_back(groupB);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends