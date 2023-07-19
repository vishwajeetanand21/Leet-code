//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int transitionPoint(int arr[], int n) {
    // code here
    /*
    LOGIC: Traverse from right to left and keep the check of 1s
    */
    
    int ansIndex=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==1)
        {
            ansIndex=i;
        }
        if(arr[i]==0)
        {
            break;
        }
    }
    return ansIndex;
}