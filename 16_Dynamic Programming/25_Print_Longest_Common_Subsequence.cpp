string findLCS(int n, int m,string &str1, string &str2){
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
		string ans="";
        int i=n,j=m;
        while(i>0 && j>0) // >0 because 0 pe to sab 0 hi set kar rakha hai
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1];
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                {
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }
        reverse(ans.begin(),ans.end()); // reverse the string to get the correct order because we started from the end of the strings
		return ans;
	
}