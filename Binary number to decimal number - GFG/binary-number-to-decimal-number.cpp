//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int binary_to_decimal(string str) 
    {
        // Code here.
        int n=str.size();
        int power=0;
        
        int answer=0;
        
        for(int i=n-1; i>=0;i--)
        {
            int a=str[i]-'0';   //IMPORTANT: to convert char '1' to int '1'
            int b= pow(2, power);
            
            answer+= a*b;
            
            power++;
        }
        
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends