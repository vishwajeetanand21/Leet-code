//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    /*
    LOGIC: We can observe that 
        2^1^5^9=15
        
        and 2^15=13
            1^15=14
            5^15=10
            9^15=6
    */
    vector<int> getXor(vector<int> arr, int n)
    {
        // STEP 1: Take a xor of all elements
        int xorAll=0;
        for(int i=0;i<n;i++)
        {
            xorAll^=arr[i];
        }
        
        vector<int>answer;
        
        // STEP 2: Take a currentElement and totalXOR, and add it to the answer array
        for(int i=0;i<n;i++)
        {
            int temp=arr[i]^xorAll;
            answer.push_back(temp);
        }
        
        return answer;
    }
    // BRUTE FORCE APPROACH 
    /*
    vector<int> getXor(vector<int> arr, int n)
    {
        // Write your Code here
        vector<int>answer;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    temp^=arr[j];
                }
            }
            answer.push_back(temp);
        }
        return answer;
    }
    */
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N ;
        vector<int> A(N);

        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        Solution ob;
        vector<int> B = ob.getXor(A, N);
        for(int i = 0 ; i < N ; i++)
        {
            cout << B[i] <<" ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends