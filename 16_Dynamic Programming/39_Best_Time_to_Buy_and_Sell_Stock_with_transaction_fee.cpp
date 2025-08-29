class Solution {
public:
    int find(vector<int>&prices,int i,int n,int buy,int fee,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        int ans=0;
        if(buy)
        {
            int take=-prices[i]+find(prices,i+1,n,!buy,fee,dp);
            int ntake=find(prices,i+1,n,buy,fee,dp);
            ans=max(take,ntake);
        }
        else
        {
            int take=(prices[i]+find(prices,i+1,n,!buy,fee,dp))-fee;
            int ntake=find(prices,i+1,n,buy,fee,dp);
            ans=max({ans,take,ntake});
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return find(prices,0,n,1,fee,dp);
        

        // dp solution.
        
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

        for(int i=0;i<2;i++)
        {
            dp[n][i]=0;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<2;buy++)
            {
                int ans=0;
                if(buy)
                {
                    int take=-prices[i]+dp[i+1][!buy];
                    int ntake=dp[i+1][buy];
                    ans=max(take,ntake);
                }
                else
                {
                    int take=prices[i]-fee+dp[i+1][!buy];
                    int ntake=dp[i+1][buy];
                    ans=max({ans,take,ntake});
                }
                dp[i][buy]=ans;
            }
        }
        return dp[0][1];

    }
};