/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

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