class Solution {
public:
    void mergeTwoArr(vector<int>&part1, vector<int>&part2, int n, int m, vector<int>&arr)
    {
        int i=0, j=0;
        while(i<n && j<m)
        {
            if(part1[i]<=part2[j])
            {
                arr.push_back(part1[i]);
                i++;
            }
            else
            {
                arr.push_back(part2[j]);
                j++;
            }
        }
        while(i<n)
        {
            arr.push_back(part1[i]);
            i++;
        }
        while(j<m)
        {
            arr.push_back(part2[j]);
            j++;
        }
    }
    double findMedianSortedArrays(vector<int>& part1, vector<int>& part2) 
    {
        int n=part1.size();
        int m=part2.size();

        vector<int>arr;

        mergeTwoArr(part1, part2, n, m, arr);

        int arrSize=arr.size();


        if(arrSize %2==0)
        {
            int a=arr[arrSize/2];
            int b=arr[(arrSize-1)/2];

            double ans=(double)(a+b)/2;
            return ans;
        }
        else
        {
            double ans=arr[arrSize/2];
            return ans;
        }

        // return ans;
    }
};