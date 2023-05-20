class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n=arr.size();

        int zeros=0, ones=0, twos=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) zeros++;
            else if(arr[i]==1) ones++;
            else twos++;
        } 

        for(int i=0;i<zeros;i++)
            arr[i]=0;

        for(int i=zeros; i<zeros+ones;i++)
            arr[i]=1;
        
        for(int i=zeros+ones; i<n;i++)
            arr[i]=2;
    }
};