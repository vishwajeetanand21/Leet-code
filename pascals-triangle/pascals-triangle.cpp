class Solution {
public:
   long long int factorial(int n)
    {
        if(n==0)
        {
            return 1;
        }
        long long int ans=1;
        for(int i=n;i>=1;i--)
        {
            ans*=i;
        }
        return ans;
    }

    int nCr(int n, int r)
    {
        int res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }


    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>answer;

        for(int i=1;i<=n;i++)
        {
            vector<int>temp;
            for(int j=1;j<=i;j++)
            {
                int currElement=nCr(i-1, j-1);
                temp.push_back(currElement);
            }
            answer.push_back(temp);
        }

        return answer;

    }
};