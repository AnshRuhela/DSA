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
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string s2=s;
        reverse(s2.begin(),s2.end());
        int lps=find(n,n,s,s2,dp); // lps means longest palendromic subsequence.
        return n-lps;
    }
};