class Solution {
public:
    vector<int> singleNumber(vector<int>& A) 
    {
        int n=A.size();
        int mask=1;
        int Xor=0;
        for(int i=0;i<n;i++)
        {
            Xor^=A[i];
            
        }
        
        while((Xor &mask)==0)
        {
            mask<<=1;
        }
        
        int j=0,k=0;
        
        for(int i=0;i<n;i++)
        {
            if((mask & A[i])==0) j^=A[i];
            else k^=A[i];
            
        }
        cout<<mask;
        
        vector<int>ans;
        ans.push_back(j);
        ans.push_back(k);
        return ans;
    }

    /* BRUTE FORCE METHOD: USING MAP
    vector<int> singleNumber(vector<int>& arr) 
    {
        int n=arr.size();

        unordered_map<int, int>myMap;
    
        for(int i=0;i<n;i++)
        {
            myMap[arr[i]]++;
        }
        
        vector<int>ans;
        for(auto i:myMap)
        {
            if(i.second==1)
            {
                ans.push_back(i.first);
            }
        }
    
        return ans;    
    }
    */
};