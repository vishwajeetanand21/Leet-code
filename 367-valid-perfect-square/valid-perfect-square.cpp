class Solution {
public:
    bool isPerfectSquare(int num) {
        int squareRoot=sqrt(num);

        return squareRoot*squareRoot==num;
    }
};