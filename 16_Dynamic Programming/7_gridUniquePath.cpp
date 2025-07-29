class Solution {
    int memoization(int m, int n, vector<vector<int>>& dp) {
        if (m == 0 && n == 0)
            return 1;
        if (m < 0 || n < 0)
            return 0;
        if (dp[m][n] != -1)
            return dp[m][n];
        int l = memoization(m, n - 1, dp);
        int t = memoization(m - 1, n, dp);
        return dp[m][n] = l + t;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoization(m - 1, n - 1, dp);
        dp[0][0]=1;
        for(int m1=0;m1<m;m1++) // for loops 0 se hi start honge naki 1 se kuki [0,1],[0,2].... ye bhi handle karne hai.
        {
            for(int n1=0;n1<n;n1++)
            {
                if(m1==0 && n1==0) continue; // ye important ye karna padega.
                int l=0,r=0;
                if(n1>0)
                    l=dp[m1][n1-1];
                if(m1>0)
                    r=dp[m1-1][n1];

                dp[m1][n1]=l+r;
            }
        }
        return dp[m-1][n-1];
    }
};
