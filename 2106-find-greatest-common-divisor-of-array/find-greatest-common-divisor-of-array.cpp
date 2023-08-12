class Solution {
public:

		/*
	                                             NORMAL METHOD
	                
	   A=36
	   B=60
	   
	   STEP 1: Find all the factors of A and B
	   A=2x2x3x3
	   B=2x2x3x5
	   
	   STEP 2: Find all the common factors
	   A=[2]x[2]x[3]x3
	   B=[2]x[2]x[3]x5
	   
	   STEP 3: Do the multiplication of all the factors of A and B
	   2x2x3
	   12 
	   Therefore the GCD/HCF of 36 and 60 is 12
	   
	   
	   
	   
	                                             ECULIDEAN ALGORITHM
	   METHOD 1: Using Subtraction
	   
	   We subtract smaller number from the larger number untill mini not becomes 0
	   
	   A=36 (mini)
	   B=60 (maxi)
	   
	   maxi-mini=subtractedValue
	   
	   60-36=24        {subtract mini from maxi number}
	   36-24=12        {now interchange the value, maxi=mini and mini=subtracted value}
	   24-12=12 
	   12-12=0
	   12-0=12
	   
	   At last if the value of mini=0 then our answer will be stored at maxi
	   TC: O(min(a,b))
	   
	   
	   
	   
	   METHOD 2: Using remainder
	   
	   We divide larger number from smaller number untill mini not becomes 0
	   
	   A=36  (mini)
	   B=60  (maxi)
	   
	   maxi%mini=remainder
	   60%36=24         {Divide maxi from mini and get the remainder}
	   36%24=12         {now interchange the value maxi=mini and mini=remainder}
	   24%12=0
	   12%0=0
	   
	   At last if the value of mini=0 then our answer will be stored at maxi
	   TC: O(log(min(a,b)))
	*/




    // using recursion
    int GCD2(int a, int b)
    {
        // base case
        if(a==0)
            return b;
        // recursive call
        return GCD2(b%a, a);
    }

    // using loop
    int GCD(int a, int b)
    {
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