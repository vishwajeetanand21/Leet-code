class Solution {
public:
    int countSetBit(int n)
    {
        int count=0;
        while(n>0)
        {
            if(n&1==1)
            {
                count++;
            }
            n=n>>1;
        }
        return count;
    }
    int minBitFlips(int start, int goal) {
        int num=start^goal;

        return countSetBit(num);
    }
};