// function to find longest common subsequence

class Solution {
  public:
  
  
  int find(int ind1,int ind2,string &str1,string &str2, vector<vector<int>>&dp)
  {
      if(ind1==0 || ind2==0)
      return 0;
      
      
      if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
      if(str1[ind1-1]==str2[ind2-1])
      {
          return dp[ind1][ind2]= 1+find(ind1-1,ind2-1,str1,str2,dp);
      }
      else
      {
          return dp[ind1][ind2]= max(find(ind1-1,ind2,str1,str2,dp),find(ind1,ind2-1,str1,str2,dp));
      }
  }
    int lcs(int n, int m, string str1, string str2) {
        // we considered 1 based indexing means we are assuming the length of the strings not the indexes.
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
               if(str1[i-1]==str2[j-1])
                   {
                     dp[i][j]= 1+dp[i-1][j-1];
                   }
               else
                   {
                     dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                   }
            }
        }
        
        return dp[n][m];
        
    }
};