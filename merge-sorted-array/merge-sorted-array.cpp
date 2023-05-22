class Solution {
public:
    /*
    METHOD 2: Better solution: By using constant space
    LOGIC: Step 1: We will maintain 2 pointer.
           One at the last index of first array and one at the first index of the second array
           
           Step 2: Then we will compare if firstArr[lastElement]>secondArray[firstElement]
           YES: then swap both the element and decrement the first pointer and increment the second pointer
           NO: then simply decrement the first pointer and increment the second pointer

           Step 3: When the traversal will be completed all the elements will be at the correct array
                   but in a random order. Therefore sort both the array
    
    DRY RUN: arr1=[1,3,5,7] n=4     arr2=[0,2,6,8,9] m=5
    STEP 1: Maintain two pointer
            last=arr1[n-1]   first=arr2[0]
    STEP 2: while(last >=0 && first<m)
            {
                if(arr1[last]>arr2[first])
                    swap(arr1[last], arr2[first])
                    last--; first++;
                else
                    last--; first++;
            }
    STEP 3: sort(arr1) and sort(arr2)
    
    void merge(vector<int>& arr1, int m, vector<int>& arr2, int n)
    {
        int last=m-1;
        int first=0;

        while(last>=0 && first<n)
        {
            if(arr1[last]>arr2[first])
            {
                swap(arr1[last], arr2[first]);
                last--;
                first++;
            }
            else
            {
                last--;
                first++;
            }
        }
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        // 

    }*/
    // METHOD 1: BRUTE FORCE (Using the logic of merge sort) and taking an extra space of O(m+n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //merging from the end of the array
        int i=m-1;
        int j=n-1;
        int k=(m+n)-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        // while(i>=0)
        // {
        //     nums1[k]=nums1[i];
        //     k--;
        //     i--;
        // }
        while(j>=0)
        {
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
};