class Solution {
public:
    int findGCD(int a, int b)
    {
        while (a > 0 && b > 0) {
            if (a > b) {
                a = a % b;
            }
            else {
                b = b % a;
            }
        }
        if (a == 0) {
            return b;
        }
        return a;
    }
    int findGCD(vector<int>& arr) 
    {
        // find the maximum and minimum element in the array
        int maxi=INT_MIN;
        int mini=INT_MAX;

        for(int i=0;i<arr.size();i++)
        {
            maxi=max(arr[i], maxi);
            mini=min(arr[i], mini);
        } 

        return findGCD(mini, maxi);
    }
};