class Solution {
public:
    int find(vector<int>&prices,int i,int n,int buy,vector<vector<int>>&dp)
    {
        if(i>=n)
        {
            return 0; // it means yha din khatam hogye ab kuch nahi kar sakte agar bought kiya hai to gye paise and if sell kiya hai to aagye.
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        int ans=0;
        if(buy)
        {
            int take=-prices[i]+find(prices,i+1,n,!buy,dp);
            int ntake=find(prices,i+1,n,buy,dp);
            ans=max(take,ntake);
        }
        else
        {
            int take=prices[i]+find(prices,i+2,n,!buy,dp);
            int ntake=find(prices,i+1,n,buy,dp);
            ans=max({ans,take,ntake});
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(prices,0,n,1,dp);
    }
};