
// final easy.

class Solution {
public:
    int find(vector<int>&coins,int amount,int n,vector<int>&dp)
    {
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int ans=1e8;
        for(auto am:coins)
        {
            if(amount>=am)
            {
                ans=min(ans,1+find(coins,amount-am,n,dp));
            }
        }
        return dp[amount]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        // int ans= find(coins,amount,n,dp);

        //  if(ans==1e8) return -1; 
        // else return ans;

        dp[0]=0;

        for(int i=1;i<=amount;i++)
        {
            int ans=1e8;
            for(auto am:coins)
            {
                if(i>=am)
                {
                    ans=min(ans,1+dp[i-am]);
                }
            }
            dp[i]=ans;
        }

        if(dp[amount]==1e8) return -1;
        else return dp[amount];
    }
};

/*

1d dp easy

class Solution {
public:
    int find(vector<int>&coins,int amount,int n,vector<int>&dp)
    {
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int ans=1e8;
        for(auto am:coins)
        {
            if(amount-am>=0)
            {
                ans=min(ans,1+find(coins,amount-am,n,dp));
            }
        }
        return dp[amount]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int ans= find(coins,amount,n,dp);
        if(ans==1e8) return -1;
        else return ans;
    }
};

*/

/*

2-D dp (easy)

class Solution {
public:
    int find(int i,vector<int>&coins,int am,int n,vector<vector<int>>&dp)
    {
        if(am==0) return 0;
        else if(i==n) return 1e8;

        if(dp[i][am]!=-1) return dp[i][am];
        int ntake=find(i+1,coins,am,n,dp);
        int take=1e8;
        if(am>=coins[i])
        {
            take=1+find(i,coins,am-coins[i],n,dp);
        }
        return dp[i][am]= min(take,ntake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= find(0,coins,amount,n,dp);
        if(ans==1e8) return -1;
        else return ans;
    }
};

*/