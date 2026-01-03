/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/


class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // return find(n,dp);
        if(n>=1)
        dp[1]=1;
        if(n>=2)
        dp[2]=2;
        for(int ind=3;ind<=n;ind++)
        {
            dp[ind]=dp[ind-1]+dp[ind-2];
        }
        return dp[n];
    }
};