#include <bits/stdc++.h> 

int find(vector<vector<int>>&grid,int r,int c, int i,int j1,int j2,vector<vector<vector<int>>>&dp)
{
    if(j1<0 || j1==c || j2<0 || j2==c) // agar out of bound gya 
    {
        return -1e9;
    }
    if(i==r-1) 
    {
        if(j1==j2) return grid[i][j1]; // agar dono same cell me hue
        else return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    int ans=-1e8;
    int dj[]={-1,0,1};
    for(auto k : dj) // trying all the possible combinations.
    {
        for(auto l:dj)
        {
            int cc1=j1+k;
            int cc2=j2+l;
            int ans2=0;
            if(j1==j2) // again agar dono same call me hue.
            {
                ans2=grid[i][j1]+find(grid,r,c,i+1,cc1,cc2,dp);
            }
            else // verna dono ka sum plus hoga.
            {
                ans2=grid[i][j1]+grid[i][j2]+find(grid,r,c,i+1,cc1,cc2,dp);
            }
            ans=max(ans,ans2);
        }
    }
    return dp[i][j1][j2]= ans;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return find(grid,r,c,0,0,c-1,dp);
}