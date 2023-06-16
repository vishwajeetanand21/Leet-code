class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) 
    {
        // size of the array
        int n=arr.size();

        // sort the array in increasing order
        sort(arr.begin(), arr.end());

        // base case
        if(n<3)
        {
            return {};
        }

        // base case
        if(arr[0]>0)
        {
            return {};
        }

        // vector to store the answer
        vector<vector<int>>answer;

        for(int i=0;i<n-2;i++)
        {
            if(arr[i]>0)
            {
                break;
            }
            if(i>0 && arr[i]==arr[i-1])
            {
                continue;
            }
            int left=i+1, right=n-1;
            int sum=0;

            while(left<right)
            {
                sum =arr[i]+arr[left]+arr[right];

                if(sum<0)
                {
                    left++;
                }
                else if(sum>0)
                {
                    right--;
                }
                else
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[left]);
                    temp.push_back(arr[right]);
                    answer.push_back(temp);

                    int last_left_occurance=arr[left];
                    int last_right_occurance=arr[right];

                    while(left<right && arr[left]==last_left_occurance)
                        left++;
                    while(left<right && arr[right]==last_right_occurance)
                        right--;
                }
            }
        }
        return answer;
    }
};