#include<bits/stdc++.h>
int find(int ind,int cap,vector<int>profit,vector<int>weight,vector<vector<int>>&dp)
{
    if(cap==0)
    return 0;
    if(ind==0)
    {
        if(cap>=weight[0])
        {
            return (cap/weight[0])*profit[0];
        }
        else
        return 0;
    }

    if(dp[ind][cap]!=-1) return dp[ind][cap];

    int nt=find(ind-1,cap,profit,weight,dp);
    int t=INT_MIN;
    if(cap>=weight[ind])
    {
        t=profit[ind]+find(ind,cap-weight[ind],profit,weight,dp);
    }
    return dp[ind][cap]= max(t,nt);

}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,0));
   //return find(n-1,w,profit,weight,dp);

    for(int i=0;i<n;i++)
    {
        dp[i][0]=0;
    }
    for(int cap=0;cap<=w;cap++)
    {
        if(cap>=weight[0])
        {
            dp[0][cap]=(cap/weight[0])*profit[0];
        }
    }

    for(int ind=1;ind<n;ind++)
    {
        for(int cap=1;cap<=w;cap++)
        {
            int nt=dp[ind-1][cap];
            int t=INT_MIN;
            if(cap>=weight[ind])
            {
                t=profit[ind]+dp[ind][cap-weight[ind]];
            }

            dp[ind][cap]=max(nt,t);
        }
    }

    return dp[n-1][w];
}