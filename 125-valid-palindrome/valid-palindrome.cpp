class Solution {
public:
    bool checkPalindrome(string str)
    {
        int i=0, j=str.size()-1;
        while(i<=j)
        {
            if(str[i]!=str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string str) 
    {
        string myStr;

        for(int i=0;i<str.size();i++)
        {
            if(iswalnum(str[i])==false)
            {

            }
            else
            {
                myStr.push_back(str[i]);
            }
        }
        for(int i=0;i<myStr.size();i++)
        {
            if(myStr[i]>='A' && myStr[i]<='Z')
            {
                myStr[i]=myStr[i]+32;
            }
        }
        // cout<<myStr;

        return checkPalindrome(myStr);
    }
};