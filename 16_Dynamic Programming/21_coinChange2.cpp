class Solution {
public:

    int find(int amount,vector<int>coins,int ind,vector<vector<int>>&dp)
    {
        if(ind==0) 
        {
            if(amount%coins[0]==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake=find(amount,coins,ind-1,dp);

        int take=0;
        
        if(amount>=coins[ind])
        {
            take=find(amount-coins[ind],coins,ind,dp);
        }

        return dp[ind][amount] =take+nottake;

        
    }

    int change(int amount, vector<int>& coins) {

        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        // return find(amount,coins,coins.size()-1,dp);

        for(int i=0;i<=amount;i++)
        {
            if(i%coins[0]==0)
            {
                dp[0][i]=1;
            }
            else
            {
                dp[0][i]=0;
            }
        }

        for(int i=1;i<coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                int nottake=dp[i-1][j];

                int take=0;

                if(j>=coins[i])
                {
                    take=dp[i][j-coins[i]];
                }

                dp[i][j]=take+nottake;
            }
        }

        return dp[coins.size()-1][amount];

    }
};