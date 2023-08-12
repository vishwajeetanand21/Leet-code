class Solution {
public:
    // using recursion
    int GCD2(int a, int b)
    {
        // // base case
        // if(a==0)
        //     return b;
        // // recursive call
        // return GCD2(b%a, a);
        int maxi=max(a,b);
	    int mini=min(a,b);
	    
	    int rem;
	    
	    while(maxi>0 && mini>0)
	    {
	        rem=maxi%mini;
	        
	        maxi=mini;
	        mini=rem;
	    }
	    
	    if(mini==0)
	        return maxi;
        return 0;
    }

    // using loop
    int GCD(int a, int b)
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

        return GCD2(mini, maxi);
    }
};