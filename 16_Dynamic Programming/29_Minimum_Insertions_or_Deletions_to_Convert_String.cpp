// similar to the leetcode problem 583 vha bas delete karne hai dono string me and then equal karna hai
//  but here we have to find the minimum insertions and deletions to convert one string to another

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
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int lcs=find(n,m,word1,word2,dp);
        return n+m-(2*lcs);
    }
};