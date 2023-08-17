//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int isSquare(string S);

int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        cout << isSquare(S) << endl;
    }
return 0;
}
// } Driver Code Ends


bool isPerfect(int n)
{
    int squareRoot=sqrt(n);
    return squareRoot*squareRoot==n;
}
int isSquare(string str){
    //complete the function here
    int sum=0;
    for(int i=0;i<str.size();i++)
    {
        sum+=str[i];   
    }
    
    return isPerfect(sum);
}