class Solution {
public:
    int reverse(int x) 
    {
        long long res=0;
        while(x){
            int rem=x%10;
            x=x/10;
            res=res*10+rem;
        }
        if(res>=INT_MAX || res<=INT_MIN){
            return 0;
        }
        return res;        
    }
};