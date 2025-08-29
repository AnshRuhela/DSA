class Solution {
public:
    int find(vector<int>&prices,int n,bool buy,int trans,int ind,vector<vector<vector<int>>>&dp)
    {
        if(trans==0)
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
            int take=-prices[ind]+find(prices,n,!buy,trans,ind+1,dp);
            int ntake=find(prices,n,buy,trans,ind+1,dp);
            ans=max(ntake,take);    
        }
        else
        {
            int sell = prices[ind]+find(prices,n,!buy,trans-1,ind+1,dp);
            int notSell = find(prices,n,buy,trans,ind+1,dp);
            ans=max(sell,notSell);
        }

        return dp[ind][trans][buy]=ans;

    }
    int maxProfit(int k,vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return find(prices,n,true,k,0,dp);
    }
};