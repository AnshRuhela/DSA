/*
Problem statement
You are given ‘n’ items with certain ‘profit’ and ‘weight’ and a knapsack with weight capacity ‘w’.

You need to fill the knapsack with the items in such a way that you get the maximum profit. You are allowed to take one item multiple times.

Example:
Input: 
'n' = 3, 'w' = 10, 
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

Output: 27

Explanation:
We can fill the knapsack as:

1 item of weight 6 and 1 item of weight 4.
1 item of weight 6 and 2 items of weight 2.
2 items of weight 4 and 1 item of weight 2.
5 items of weight 2.

The maximum profit will be from case 3 = 11 + 11 + 5 = 27. Therefore maximum profit = 27.
*/

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