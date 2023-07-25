class Solution {
public:
    int numberOfBits(int n)
    {
        int ans=0;
        while(n>0)
        {
            if(n&1==1)
            {
                ans++;
            }
            n=n>>1;
        }
        return ans;
    }
    vector<int> countBits(int n) 
    {
        vector<int>answer;

        for(int i=0;i<=n;i++)
        {
            int temp=numberOfBits(i);
            answer.push_back(temp);
        }

        return answer;    
    }
};