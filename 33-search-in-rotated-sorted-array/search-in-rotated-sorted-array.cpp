class Solution {
public:
    int search(vector<int>& arr, int k) 
    {
        int n=arr.size();

        int low=0;
        int high=n-1;

        while(low<=high)
        {
            int mid=(low+high)/2;
            
            // the target is present at the middle of the array
            if(arr[mid]==k)
            {
                return mid;
            }

            // left half is sorted
            if(arr[low]<=arr[mid])
            {
                if(arr[low]<=k && k<=arr[mid])
                {
                    high=mid-1;
                }
                else //element does not exist in left half
                {
                    low=mid+1;
                }
            }
            else
            {
                if(arr[mid]<=k && k<=arr[high])
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};