class Solution {
public:
    vector<vector<int>> longestCommonSubsequence(string str1, string str2) {
        // we considered 1 based indexing means we are assuming the length of the strings not the indexes.
        int n = str1.length(),m = str2.length();
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
        
        return dp;
        
    }
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp = longestCommonSubsequence(str1 , str2);// set dp array of lcs.

        string ans = "";
        int m = str1.length() , n = str2.length();
        int i = m , j = n;
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    ans += str2[j-1];
                    j--;
                }
                else{
                    ans += str1[i-1];
                    i--;
                }
            }
        }

        //adding those characters which we are left with
        while(i > 0){
            ans += str1[i-1];
            i--;
        }
        while(j > 0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};