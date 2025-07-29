// coding ninjas.

#include <bits/stdc++.h> 
// frog jump
int find(int ind,vector<int>&arr, vector<int>&dp)
{
    if(ind==0)
    {
        return 0;
    }
    if(dp[ind]!=-1) return dp[ind];
    int one=abs(arr[ind]-arr[ind-1])+find(ind-1,arr,dp);
    int two=INT_MAX;
    if(ind>1)
     two=abs(arr[ind]-arr[ind-2])+find(ind-2,arr,dp);

    return dp[ind]= min(one,two);
}

int frogJump(int n, vector<int> &heights)
{
    // vector<int>dp(n,-1);
    // return find(n-1,heights,dp);

    // dp[0]=0; don't even need dp array
    int prev=0;
    int prev2=0;
    for(int ind=1;ind<n;ind++)
    {
        int one=abs(heights[ind]-heights[ind-1])+prev;
        int two=INT_MAX;
        if(ind>1)
        {
            two=abs(heights[ind]-heights[ind-2])+prev2;
        }
        // dp[ind]=min(one,two);
        prev2=prev;
        prev=min(one,two);
    }
    // return dp[n-1];
    return prev; // when for loop ends i will at n and prev is at n-1 so prev is our answer.
}