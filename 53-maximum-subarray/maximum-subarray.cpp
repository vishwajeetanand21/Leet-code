#include <bits/stdc++.h>
class Solution {
public:
    // LOGIC: KADANE'S ALGO
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();

        int answer=INT_MIN;
        int answerTillHere=0;

        
        for(int i=0;i<n;i++)
        {
            answerTillHere += arr[i];

            /*
            if(answerTillHere > answer)
            {
                answer= answerTillHere;
            }
            */
            answer=max(answer, answerTillHere);

            if(answerTillHere<0)
            {
                answerTillHere=0;
            }
        }
        return answer;
    }
};