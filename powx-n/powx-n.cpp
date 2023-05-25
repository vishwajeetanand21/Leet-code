class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0;
        int nn=n;
        if(nn<0)
            nn= abs(nn);
        while (nn > 0) {
            if (nn & 1 == 1) // y is odd
            {
                result = result * x;
            }
            x = x * x;
            nn = nn >> 1; // y=y/2;
        }
        if(n<0)
            result=(double)1.0 / (double) result;

        return result;
    }
};