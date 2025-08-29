class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // optimized

        int buyprice=prices[0];

        int finalprice=0;

        for(int i=1;i<prices.size();i++)
        {
            if(buyprice>prices[i])
            {
                buyprice=prices[i];
            }

            finalprice=max(finalprice,prices[i]-buyprice);

        }

        return finalprice;

    }
};