class Solution {
public:

    int find(string &s,string &t , int i,int j,vector<vector<int>>&dp)
    {
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ntake=find(s,t,i-1,j,dp);
        int take=0;
        if(s[i-1]==t[j-1])
        {
            take=find(s,t,i-1,j-1,dp);
        }

        return dp[i][j]= take+ntake;
    }

    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return find(s,t,n,m,dp);
    }
};