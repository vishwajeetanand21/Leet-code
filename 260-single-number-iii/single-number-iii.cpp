class Solution {
public:
    /*
    LOGIC: BIT MANIPULATION
           
           [1,2,1,3,2,5]

    STEP 1: Take the XOR of all the elements
            Xor=3^5      Because XOR of two same numbers are 0
    
    STEP 2: Observe
            Xor=3^5
               =0 1 1 ^ 1 0 1
               =1 1 0 =6
               ->The first set bit is at 1st index position, we can say that
               at 1st index the bit differs
               ->Same way at 1st index of 3 it will be a SET bit and in 5 at 1st index it will
               be a UNSET bit
               THEREFORE AT 1ST INDEX 3 AND 5 ARE DIFFERING IN BITS

    STEP 3: Divide the elements into two groups according to their 1st index bit
            SET1: 3=0 1 1
            SET2: 5=1 0 1

            1->0 (0) 1  SET2
            2->0 (1) 0  SET1
            1->0 (0) 1  SET2
            3->0 (1) 1  SET1
            2->0 (1) 0  SET1
            5->1 (0) 1  SET2

            If the 1st index bit will be 1->SET1 or 0->SET2

            SET1: 2 3 2
            SET2: 1 1 5

    STEP 4: Perform XOR Operation on both the set, the remaining elements will be the answer
    */
    vector<int> singleNumber(vector<int>& A) 
    {
        int n=A.size();

        // SETP 1: Doing XOR operation of all the elements
        int Xor=0;
        for(int i=0;i<n;i++)
        {
            Xor^=A[i];  
        }
        
    // STEP 2: Creating a mask, at which index the bit differs (at 1st index the bit differs) 
        int mask=1;
        while((Xor & mask)==0)
        {
            mask<<=1;
        }
        // now the mask will be: 0 1 0  at 1st index the bit differs
        
        // STEP 3: Creating two sets
        int set1=0,set2=0;
        
        for(int i=0;i<n;i++)
        {
            if((mask & A[i])==0) //if the element's 1st index bit is same
                set1^=A[i];// put it in SET1
            else 
                set2^=A[i];//otherwise put it in SET2
            
        }

        // The XOR of both the SETS are our answer
        vector<int>ans;
        ans.push_back(set1);
        ans.push_back(set2);
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