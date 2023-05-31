//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int mergeTwoArray(vector<long long>&part1, vector<long long>&part2, vector<long long >&output)
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
                invCount += (size1-i);
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
    long long int mergeSort(vector<long long>&arr)
    {
        long long n=arr.size();
        
        if(n==0 || n==1)
        {
            return 0;
        }
        
        long long mid=n/2;
        // long long size1= mid, size2= n-mid;
        
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