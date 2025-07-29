class Solution {
public:
    bool find(int i,int j,string& s1,string& s2,string& s3,int n1,int n2,int n3,vector<vector<int>>&dp)
    {
        
        if(i==n1)
        {
            string str1=s3.substr(j+i,n3-(j+i));
            string str2=s2.substr(j,n2-j);
            if(str1==str2) return true;
            else return false;
        }

         if(j==n2)
        {
            string str1=s3.substr(j+i,n3-(j+i));
            string str2=s1.substr(i,n1-i);
            if(str1==str2) return true;
            else return false;
        }

        if(s1[i]!=s3[i+j] && s2[j]!=s3[i+j])
        {
            return false;
        }
    
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s3[i+j] && s3[i+j]!=s2[j])
        {
            return dp[i][j]=find(i+1,j,s1,s2,s3,n1,n2,n3,dp);
        }
        else if(s2[j]==s3[i+j] && s1[i]!=s3[i+j])
        {
            return dp[i][j]=find(i,j+1,s1,s2,s3,n1,n2,n3,dp);
        }
        else 
        {
            return dp[i][j]=find(i,j+1,s1,s2,s3,n1,n2,n3,dp)||find(i+1,j,s1,s2,s3,n1,n2,n3,dp);
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(n1+n2!=n3) return false;
        // vector<vector<int>>dp(n1,vector<int>(n2,-1));
        // return find(0,0,s1,s2,s3,n1,n2,n3,dp);

        // tabulation

        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));

        for(int i=0;i<=n2;i++)
        {
            if(s2.substr(i,n2-i)==s3.substr(i+n1,(n3-i+n1)))
            {
                dp[n1][i]=true;
            }
            else
            {
                dp[n1][i]=false;
            }
        }

         for(int i=0;i<=n1;i++)
        {
            if(s1.substr(i,n1-i)==s3.substr(i+n2,(n3-(i+n2))))
            {
                dp[i][n2]=true;
            }
            else
            {
                dp[i][n2]=false;
            }
        }

        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                if(s1[i]==s3[i+j] && s3[i+j]!=s2[j])
                {
                     dp[i][j]=dp[i+1][j];
                }
                else if(s2[j]==s3[i+j] && s1[i]!=s3[i+j])
                {
                     dp[i][j]=dp[i][j+1];
                }
                else if(s1[i]!=s3[i+j] && s2[j]!=s3[i+j])
                {
                    dp[i][j]=false;
                }
                else 
                {
                     dp[i][j]=dp[i][j+1]||dp[i+1][j];
                }
            }
        }

        return dp[0][0];


        
    }
};