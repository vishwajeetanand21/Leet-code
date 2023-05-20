class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int current_price=INT_MAX;
        int profit=0;

        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<current_price)
            {
                current_price=prices[i];
            }
            else if(prices[i]-current_price>profit)
            {
                profit=prices[i]-current_price;
            }
        }
        return profit;
    }
};