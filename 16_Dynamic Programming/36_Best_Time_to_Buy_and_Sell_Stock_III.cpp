class Solution {
public:
    int find(vector<int>&prices,int n,bool buy,int trans,int ind,vector<vector<vector<int>>>&dp)
    {
        if(trans==0) // this new thing added.
        {
            return 0;
        }
        if(ind==n)
        {
            return 0;
        }
        if(dp[ind][trans][buy]!=-1) return dp[ind][trans][buy];
        int ans=0;
        if(buy)
        {
            int take=-prices[ind]+find(prices,n,!buy,trans,ind+1,dp); // we didn't do trans-1 bcs abhi buy kar raha hai transaction poori nahi hui
            int ntake=find(prices,n,buy,trans,ind+1,dp);
            ans=max(ntake,take);    
        }
        else
        {
            int sell = prices[ind]+find(prices,n,!buy,trans-1,ind+1,dp); // trans-1 kiya kuki transaction poori hogyi hai.
            int notSell = find(prices,n,buy,trans,ind+1,dp);
            ans=max(sell,notSell);
        }

        return dp[ind][trans][buy]=ans;

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        // return find(prices,n,true,2,0,dp);
vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=1;trans<=2;trans++)
            {
                for(int buy=1;buy>=0;buy--)
                {  
                     int ans=0;
                      if(buy)
                    {
                        int take=-prices[ind]+dp[ind+1][trans][!buy];
                        int ntake=dp[ind+1][trans][buy];
                        ans=max(ntake,take);
                    }
                    else
                    {
                        int bechdo = prices[ind]+dp[ind+1][trans-1][!buy];
                        int nahi = dp[ind+1][trans][buy];
                        ans=max(bechdo,max(nahi,ans));
                    }

                    dp[ind][trans][buy]=ans;
                }
            }
        }

        return dp[0][2][1];
    }
};