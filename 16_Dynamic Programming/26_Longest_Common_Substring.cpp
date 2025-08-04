// similar to longest common subsequence code bas line 20 me dp[i][j]=0; karna hai and uske code me dp[i][j]=dp[i][j]= max(dp[i-1][j],dp[i][j-1]); karna hai.
class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        int n1=s1.length(),n2=s2.length();
        int ans=0;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                {
                    dp[i][j]=0;
                }
            }
        }
        return ans;
    }
};