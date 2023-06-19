class Solution {
public:
    string reverseWords(string s) 
    {
        string ans="";

        string temp="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                temp.push_back(s[i]);
            }
            else if(s[i]==' ')
            {
                reverse(temp.begin(), temp.end());
                ans=ans+temp+" ";
                temp="";
            }
        }
        reverse(temp.begin(), temp.end());
        ans=ans+temp;

        reverse(ans.begin(), ans.end());

        
        // handling the extra space in the sentence
        string answer="";

        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==' ')
            {

            }
            else if(ans[i]!=' ')
            {
                int j=i;
                while(ans[j]!=' ' && i<ans.size() && j<ans.size())
                {
                    answer.push_back(ans[j]);
                    j++;
                }
                answer.push_back(' ');
                i=j;
            }
        }
        answer.pop_back();

        return answer;
    }
};