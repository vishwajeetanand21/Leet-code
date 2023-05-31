//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    
    /*
    LOGIC: We will use merge sort to calculate the count inversion
           there is a slight modification in this code
           first -> we wil  be using vector instead of an array, because in gfg if we use vector then only all test cases are getting passed
           second-> we will maintain a invCount variable which will count the number of inversions
                 -> invCount will be updated as invCount+=(size1-i) whereever part1[i]>part2[j]
           Third -> please take care of the DATA TYPES of all the variables
                    Difference platforms have different return types, for this you have to modify the data types
           Fourth-> Use PASS BY ADDRESS instead of PASS BY VALUE
    */
    long long int mergeTwoArray(vector<long long>&part1, vector<long long>&part2, vector<long long >&output) //use pass by address
    {
        long long size1=part1.size();
        long long size2=part2.size();
        
        long long i=0,j=0,k=0;
        long long int invCount=0;
        
        while(i<size1 && j<size2)
        {
            if(part1[i]<=part2[j])
            {
                output[k++]=part1[i++];
            }
            else
            {
                output[k++]=part2[j++];
                invCount += (size1-i); //modified step
            }
        }
        while(i<size1)
        {
            output[k++]=part1[i++];
        }
        while(j<size2)
        {
            output[k++]=part2[j++];
        }
        return invCount;
    }
    long long int mergeSort(vector<long long>&arr) //use pass by address
    {
        long long n=arr.size();
        
        if(n==0 || n==1)
        {
            return 0;
        }
        
        long long mid=n/2;
        
        // the below code will automatically initialize the 2 vectors 
        vector<long long>part1 (arr.begin(), arr.begin()+mid);
        vector<long long>part2 (arr.begin()+mid, arr.end());
        
        long long int invCount=0;
        
        invCount+=mergeSort(part1);
        invCount+=mergeSort(part2);
        invCount+=mergeTwoArray(part1, part2, arr);
        
        return invCount;
    }
    long long int inversionCount(long long array[], long long n)
    {
        // Your Code Here
        
        // convert the array to a vector, because then only our code will run
        
        vector<long long>arr;
        
        for(long long i=0;i<n;i++)
        {
            arr.push_back(array[i]);
        }
        return mergeSort(arr);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends