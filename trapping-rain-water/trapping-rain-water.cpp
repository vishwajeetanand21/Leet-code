class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();

        int left[n], right[n];

        int maximum_left=left[0]=arr[0];
        int maximum_right=right[n-1]=arr[n-1];

        for(int i=1;i<n;i++)
        {
            if(arr[i]>maximum_left)
            {
                maximum_left=arr[i];
            }
            left[i]=maximum_left;
        }

        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>maximum_right)
            {
                maximum_right=arr[i];
            }
            right[i]=maximum_right;
        }

        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += min(left[i], right[i])-arr[i];
        }

        return sum;
    }
};