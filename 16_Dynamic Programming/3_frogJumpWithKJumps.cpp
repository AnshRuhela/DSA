// coding ninjas.

#include <bits/stdc++.h> 
// frog jump
int find(int ind,vector<int>&arr, vector<int>&dp,int k)
{
    if(ind==0)
    {
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind];

    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        int jumps=INT_MAX;
        if(ind-j>=0)
        {
            jumps=abs(arr[ind]-arr[ind-j])+find(ind-j,arr,dp,k);
        }
        minSteps=min(minSteps,jumps);
    }

    return minSteps;
}

int frogJump(int n, vector<int> &heights,int k)
{
    vector<int>dp(n,-1);
    return find(n-1,heights,dp,k);
}