//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
/*
LOGIC: SIEVE OF ERATOSTHENES

Step 1: Make in boolean array of size n+1 and initialize all as TRUE
Step 2: Initialize 0th and 1st index as false because 0 and 1 are not a prime number
Step 3: Start from 2 to √n because divisors exist in pairs
		i=2 make all the multiples of 2 as false
		i=3 make all the multiples of 3 as false
		i=4 skip because 4 is the multiple of 2
		i=5 make all the multiples of 5 as false
		...carry on with this

		Till now those index the value of True, this is a prime number

Step 4: Traverse from 2 to n
		if(arr[i]==true)
			print(i) 
*/

    vector<int> sieveOfEratosthenes(int n)
    {
        // make an boolean array of size n+1, because we are taking numbers from 0 to n(both inclusive)
        vector<bool>arr(n+1, true); //initialize the array with true
        
        // 0 and 1 are not a prime number
        arr[0]=false;
        arr[1]=false;
        
        // traverse from 2 to √n, because the divisors exist in pairs
        for(int i=2; i*i<=n; i++)
        {
            if(arr[i]==true) //this is 2
            {
                // make all the multiple of 2 as false
                for(int j=i*2; j<=n; j=j+i)
                {
                    arr[j]=false;
                }
            }
        }
        
        // finally the index which has true is the prime numbers from range 1 to n
        vector<int>answer;
        for(int i=0;i<=n;i++)
        {
            if(arr[i]==true)
            {
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends