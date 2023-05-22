//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    /*METHOD 2: Better solution: By using constant space
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
    */
        void merge(long long arr1[], long long arr2[], int m, int n) 
        {
            // STEP 1
            int last=m-1;
            int first=0;
    
            // STEP 2
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
            
            // STEP 3
            sort(arr1, arr1+m);
            sort(arr2, arr2+n);
        }
        //Function to merge the arrays.
        /*void merge(long long arr1[], long long arr2[], int m, int n) 
        { 
            // code here 
            vector<int>answer;
            
            for(int i=0;i<m;i++) answer.push_back(arr1[i]);
            
            for(int i=0;i<n;i++) answer.push_back(arr2[i]);
            
            sort(answer.begin(), answer.end());
            
            int i;
            for(i=0;i<m;i++)
            {
                arr1[i]=answer[i];
            }
            // cout<<"ANAND"<<i<<endl;
            int k=0;
            for(int j=i-1;j<n;j++)
            {
                arr2[k++]=answer[j];
            }
        } */
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends