class Solution {
public:
    int sieveAlgo(int n)
    {
        vector<bool>arr(n+1, true);

        arr[0]=false;
        arr[1]=false;

        for(int i=2;i*i<=n;i++)
        {
            if(arr[i]==true)
            {
                for(int j=i*2; j<=n;j=j+i)
                {
                    arr[j]=false;
                }
            }
        }
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