class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) 
    {
        int breakPoint;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>=0)
            {
                breakPoint=i;
                break;
            }
        }

        for(int i=0;i<arr.size();i++)
        {
            arr[i]=arr[i]*arr[i];
        }

        vector<int>ans;
        int i=breakPoint-1, j=breakPoint;
        while(i>=0 && j<arr.size())
        {
            if(arr[i]<arr[j])
            {
                ans.push_back(arr[i]);
                i--;
            }
            else
            {
                ans.push_back(arr[j]);
                j++;
            }
        }
        while(i>=0)
        {
            ans.push_back(arr[i]);
            i--;
        }
        while(j<arr.size())
        {
            ans.push_back(arr[j]);
            j++;
        }

        return ans;
    }
    /* BRUTE FORCE APPROACH
    vector<int> sortedSquares(vector<int>& arr) 
    {
        for(int i=0;i<arr.size();i++)
        {
            arr[i]= arr[i]*arr[i];
        }

        sort(arr.begin(), arr.end());

        return arr;
    }
    */
};