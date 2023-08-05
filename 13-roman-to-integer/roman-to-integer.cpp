class Solution {
public:
    /*
    LOGIC: There are two types of roman numbers
            Type 1: IV this is 4
            Type 2: VI this is 6

    TYPE 1:     if the ith character is smaller than the (i+1)th character
                then the number will be (i+1)th character - ith character
                                        V-I
                                        =5-1
                                        =4
            
    TYPE 2:     if the ith character is larger than the (i+1)th character
                then the number will be (i)th character + (i+1)th character
                                        V+I
                                        5+1
                                        6
    */
    int romanToInt(string str) 
    {
        // Initialize the map
        map<char, int>myMap;
        myMap['I']=1;
        myMap['V']=5;
        myMap['X']=10;
        myMap['L']=50;
        myMap['C']=100;
        myMap['D']=500;
        myMap['M']=1000;

        // calculate the size of the strign
        int n=str.size();

        // variable to store the answer
        int ans=0;

        // traverse throught the string (IMPORTANT: Move two index when there is TYPE 1 number)
        for(int i=0; i<n; )
        {
            int temp; // a temporary variable to store the current number

            // TYPE 2
            if(i==n-1 || myMap[str[i]] >= myMap[str[i+1]])
            {
                temp=myMap[str[i]];
                i++;
            }

            // TYPE 1
            else
            {
                temp = myMap[str[i+1]] - myMap[str[i]];
                i+=2;
            }

            // finally add the temporary variable to the answer variable
            ans+=temp;
        }      

        return ans;
    }
};