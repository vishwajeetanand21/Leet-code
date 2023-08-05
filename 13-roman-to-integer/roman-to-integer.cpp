class Solution {
public:
    int romanToInt(string str) 
    {
        map<char, int>myMap;
        myMap['I']=1;
        myMap['V']=5;
        myMap['X']=10;
        myMap['L']=50;
        myMap['C']=100;
        myMap['D']=500;
        myMap['M']=1000;

        int n=str.size();

        int ans=0;

        for(int i=0; i<n; )
        {
            int temp;
            if(i==n-1 || myMap[str[i]] >= myMap[str[i+1]])
            {
                temp=myMap[str[i]];
                i++;
            }
            else
            {
                temp = myMap[str[i+1]] - myMap[str[i]];
                i+=2;
            }
            ans+=temp;
        }      
        return ans;
    }
};