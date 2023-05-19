class Solution {
public:
    /*METHOD 2 (Optimal solution)
    In this method we will generate a list for every row
    if row=5 the answer should be {1,4,6,4,1} it's a zero based index
    we start from the second element
    we can observe that 4 6 4 1 is formed by the foumulae
    ans=1
    while(i>rows)
        ans=ans*(row-col)
        ans=ans/col;

    4 is formed by 1*(5-1)/1=4
    6 is formed by 4*(5-2)/2=6
    4 is formed by 6*(5-3)/3=4
    1 is formed by 4*(5-4)/4=1

    Therefore below is the function to calculate the elements of nth row, and it will generate a list
    */
    vector<int> nCr(int row)
    {
        int ans=1;
        vector<int>temp;
        temp.push_back(1);//because the first element is always 1
        for(int i=1;i<row;i++)//zero based indexing, here i represents column number
        {
            ans=ans*(row-i);
            ans=ans/i;
            temp.push_back(ans);
        }
        return temp;
    }
    vector<vector<int>> generate(int n)
    {
        vector<vector<int>>answer;

        for(int i=1;i<=n;i++)
        {
            vector<int>temp=nCr(i);
            answer.push_back(temp);
        }
        return answer;
    }
    /*METHOD 1 (Brute force)
    LOGIC: Every element is formed by a formulae that is: nCr=(n!)/(r! * (n-r)!)
      But there is a slight modification for this problem
      Every element is formed by the formulae (i-1)C(j-1) where i->rows and j->coolumns
    

     
    this is the best method to calculate the value of nCr
    10C3= (10*9*8*7...*1)/((3*2*1)*(7*6*5*...))
        = (10*9*8)/(3*2*1)
     or = (10*9*8)/(1*2*3) 
     or = (10/1)*(9/2)*(8/3)

     therefore 10C3 can be calculated as (10/1)*(9/2)*(8/3)
     thus the below function does calculates the same  
    
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
    }*/
};