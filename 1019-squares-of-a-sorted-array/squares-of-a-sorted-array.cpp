class Solution {
public:
    /*
    LOGIC:
    STEP 1: Find the breakPoint, the index where the positive number starts 
    STEP 2: Square all the elements
    STEP 2: Maintain two pointer i and j
            i=breakPoint-1
            j=breakPoint

    STEP 3: Create an answer array
    STEP 4: Merge the values in the answer array
            decrement the i
            increment the j


    DRY RUN
            -4  -1  0   3   10
    
    Find the breakPoint
            -4  -1  0   3   10
                    bp
    
    Square all the elements
            16  1   0   9   100
                    bp
    
    Maintain two pointer i and j, i=bp-1 and j=bp
            16    1       0      9     100
                  i     bp,j
    
    Create an answer array and merge the two sorted arrays 
    by decrementing i and by incrementing j
    */
    vector<int> sortedSquares(vector<int>& arr) 
    {
        // Finding the breakpoint
        int breakPoint;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>=0)
            {
                breakPoint=i;
                break;
            }
        }

        // Squaring all the elements
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=arr[i]*arr[i];
        }

        // creating an answer vector
        vector<int>ans;

        // maintaining two pointer
        int i=breakPoint-1, j=breakPoint;

        // code to merge two sorted arrays, by decrementing i and incrementing j
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

        // finally returning the answer
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