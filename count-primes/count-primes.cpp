class Solution {
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
    int sieveAlgo(int n)
    {
        vector<bool>arr(n+1, true);//make an boolean array of size n+1

        // 0 and 1 are not a prime number
        arr[0]=false; 
        arr[1]=false;

        // traverse from 2 to √n, because divisors exist in pairs
        for(int i=2;i*i<=n;i++)
        {
            if(arr[i]==true) //this element is 2
            {
                // make all multiple of 2 as false
                for(int j=i*2; j<=n;j=j+i)
                {
                    arr[j]=false;
                }
            }
        }

        // finally the index which has true is our a prime number
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(arr[i]==true)
            {
                ans++;
            }
        }
        return ans;
    }
    int countPrimes(int n) 
    {
        return sieveAlgo(n);        
    }
};