class Solution {
public:
    bool isDivisor(int num, int a)
    {
        if(num%a==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    bool checkPerfectNumber(int num) 
    {
        int sum=0;
        int originalNum=num;

        for(int i=1;i<num;i++)
        {
            if(isDivisor(num, i))
            {
                sum+=i;
            }
        }

        if(sum==originalNum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};