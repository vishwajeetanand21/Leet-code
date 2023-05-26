class Solution {
public:
    /*
        LOGIC: whenever we have to calculate: xⁿ, do the following step
        if n is even
            xⁿ=(x*x)^n/2    : x will be multiplied by itself and n will get half
        if n is odd
            xⁿ=(x*x)^(n-1)
        perform this operation untill n is positive 

        NOTE: if n is negative
            x^-n = 1/(xⁿ)
            in this case calculate xⁿ and at the end do 1/xⁿ 
example:
        2¹⁰
        =(2*2)⁵
        =4⁵
        =4*4⁴
        =4*(4*4)²
        =4*(16)²
        =4*(16*16)¹
        =4*(256)¹
        =4*256*(256)⁰
        =4*256*1
        =1024

example: 
        5⁵
        =5*(5)⁴
        =5*(5*5)²
        =5*25²
        =5*(25*25)¹
        =5*625¹
        =5*625*(625)⁰
        =5*625*1
        =3125
    */
    double myPow(double x, int n) {
        double result = 1.0;
        int nn=n;
        if(nn<0)
            nn= abs(nn);
        while (nn > 0) {
            if (nn & 1 == 1) // y is odd
            {
                result = result * x;
                nn=nn-1;
            }
            x = x * x;
            nn = nn >> 1; // y=y/2;
        }
        if(n<0)
            result=(double)1.0 / (double) result;

        return result;
    }
};