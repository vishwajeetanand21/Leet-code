class Solution {
public:
    string reverseWords(string s) 
    {
        // handling the extra space in the sentence
        string answer="";

        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {

            }
            else if(s[i]!=' ')
            {
                int j=i;
                while(s[j]!=' ' && i<s.size() && j<s.size())
                {
                    answer.push_back(s[j]);
                    j++;
                }
                answer.push_back(' ');
                i=j;
            }
        }
        answer.pop_back();
        //till now all the extra space have been remove from our string
        // now just we have to reverse each word and then reverse entire sentence



        string ans=""; //variable to store the answer

        string temp=""; //variable to reverse each word

        // traversing from starting index to the end index
        for(int i=0;i<answer.size();i++)
        {
            if(answer[i]!=' ') //if there is no space then add the character to the temp variable
            {
                temp.push_back(answer[i]);
            }
            else if(answer[i]==' ')//if we found a space 
            {
                reverse(temp.begin(), temp.end());//then we have to reverse that particular word
                ans=ans+temp+" ";//append that word to the answer
                temp=""; //update the temp variable to reverse the next upcoming word
            }
        }
        //handle the last word seprately
        reverse(temp.begin(), temp.end());
        ans=ans+temp;

        // reverse the entire sentence once again
        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};