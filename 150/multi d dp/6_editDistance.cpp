class Solution {
public:
    int find(string &word1,string &word2,int n1,int n2,int i,int j,vector<vector<int>>&dp)
    {   
        if(i==0) return j;
        if(j==0) return i;
       if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i-1]==word2[j-1])
        {
            return dp[i][j]= find(word1,word2,n1,n2,i-1,j-1,dp);
        }
        else
        {
            int ans2=1+find(word1,word2,n1,n2,i-1,j-1,dp);
            int ans3=1+find(word1,word2,n1,n2,i-1,j,dp);
            int  ans4=1+find(word1,word2,n1,n2,i,j-1,dp);
            return dp[i][j]= min(ans2,min(ans3,ans4));
        }
    }
    int minDistance(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        // return find(word1,word2,n1,n2,n1,n2,dp);

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=0;i<=n1;i++)
        {
            dp[i][0]=i;
        }

        for(int i=0;i<=n2;i++)
        {
            dp[0][i]=i;
        }


        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                 if(word1[i-1]==word2[j-1])
                {
                     dp[i][j]= dp[i-1][j-1];
                }
                else
                {
                    int ans2=1+dp[i-1][j-1];
                    int ans3=1+dp[i-1][j];
                    int  ans4=1+dp[i][j-1];
                     dp[i][j]= min(ans2,min(ans3,ans4));
                }
            }
        }
        return dp[n1][n2];
    }
};