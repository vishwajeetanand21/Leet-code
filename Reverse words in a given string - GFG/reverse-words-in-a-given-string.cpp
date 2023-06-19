//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // FOR LOGIC REFER TO THE LOVE BABAR'S VIDEO: GREEDY IN 1 VIDEO
        
        string ans=""; //variable to store the answer
        string temp=""; //variable to reverse each word
        
        for(int i=0;i<S.length();i++)//traversing from starting index to ending index
        {
            if(S[i]!='.')//if there is no '.' then we have to add the character in the temp variable
            {
                temp.push_back(S[i]);
            }
            else if(S[i]=='.')//whenever we get '.' it means we have to reverse the word
            //and add that reversed word to the answer string
            {
                reverse(temp.begin(), temp.end()); //reverse the word
                ans=ans+temp+"."; //add a full stop
                temp=""; //update the temp variable, because we have to reverse another upcoming words
            }
        }
        //handle the last word seprately
        reverse(temp.begin(), temp.end());
        ans=ans+temp;
        
        // reverse the entire answer once
        reverse(ans.begin(), ans.end());
        
        // finally return the answer
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends