class Solution {
public:
    /*LOGIC: Every element is formed by a formulae that is: nCr=(n!)/(r! * (n-r)!)
      But there is a slight modification for this problem
      Every element is formed by the formulae (i-1)C(j-1) where i->rows and j->coolumns
    */

    /* 
    this is the best method to calculate the value of nCr
    10C3= (10*9*8*7...*1)/((3*2*1)*(7*6*5*...))
        = (10*9*8)/(3*2*1)
     or = (10*9*8)/(1*2*3) 
     or = (10/1)*(9/2)*(8/3)

     therefore 10C3 can be calculated as (10/1)*(9/2)*(8/3)
     thus the below function does calculates the same  
    */
    int nCr(int n, int r)
    {
        int res=1;
        for(int i=0;i<r;i++)
        {
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }


    vector<vector<int>> generate(int n) {
        
        vector<vector<int>>answer;

        for(int i=1;i<=n;i++)
        {
            vector<int>temp;
            for(int j=1;j<=i;j++)
            {
                int currElement=nCr(i-1, j-1);
                temp.push_back(currElement);
            }
            answer.push_back(temp);
        }

        return answer;

    }
};