class Solution {
public:
// Same function to calculate the maximum sum in subsequence without adjacents
    int usingVariables(vector<int>arr)
    {
        int n=arr.size();

        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return arr[0];
        }

        int a=arr[0];
        int b=max(arr[0] , arr[1]);
        int c;

        for(int i=2;i<n;i++)
        {
            int pick=arr[i] + a;
            int notPick= 0 + b;

            c=max(pick, notPick);
            a=b;
            b=c;
        }
        return b;
    }
    int rob(vector<int>& arr) 
    {
        int n=arr.size();

        // base vases
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return arr[0];
        }


        vector<int>first; //this vector will contain all the elements except the first element
        vector<int>second; //this vector will contain all the element except the last element
        // because it's a circle, the first and the last house will be adjacent to each other

        for(int i=0;i<n;i++)
        {
            if(i!=0) //push back everything except the first element 
            {
                first.push_back(arr[i]);
            }
            if(i!=n-1)//push back everything except the last element
            {
                second.push_back(arr[i]);
            }
        }

        // call the find max sum in sub-sequence for the first array
        int ans1=usingVariables(first); 

        // call the find max sum in sub-sequence for the second array
        int ans2=usingVariables(second);

        // either of them will contain the answer, therefore return which is the maximum
        return max(ans1, ans2);
    }
};