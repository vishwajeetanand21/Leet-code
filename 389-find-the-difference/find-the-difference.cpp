class Solution {
public:
    // LOGIC: Do the xor of both the strings
    char findTheDifference(string s, string t) 
    {
        char ans='a';
        for(int i=0;i<s.size();i++)
        {
            ans^=s[i];
        }   
        for(int i=0;i<t.size();i++)
        {
            ans^=t[i];
        }

        return ans^'a';
    }
};