//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        // edge case
        if(n==1)
        {
            vector<long long>answer;
            answer.push_back(1);
            return answer;
        }
        
        
        vector<long long>answer;
        
        long long a=1;
        long long b=1;
        long long c;
        
        answer.push_back(1);
        answer.push_back(1);
        
        for(int i=2; i<n;i++)
        {
            c=a+b;
            answer.push_back(c);
            
            a=b;
            b=c;
        }
        
        // answer.pop_back();
        
        return answer;
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends