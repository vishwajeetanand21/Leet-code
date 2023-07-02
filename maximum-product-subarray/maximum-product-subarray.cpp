class Solution {
public:
    int maxProduct(vector<int>& arr) 
    {
	    int ans= INT_MIN;
	    int sum = 1;
	    
	   // go from left to right
	    for(int i = 0; i<arr.size(); i++){
	        sum*=arr[i];
	        ans = max(ans,sum);
	        if(sum==0) sum=1;
	    }
	    
	   // Go from right to left
	    sum = 1;
	    for(int i = arr.size()-1; i>=0; i--){
	        sum*=arr[i];
	        ans = max(ans,sum);
	        if(sum==0) sum=1;
	    }
	    
	    return ans;        
    }
};