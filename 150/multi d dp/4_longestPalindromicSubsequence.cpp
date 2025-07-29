class Solution {
public:
    bool isPalindrom(int i,int j,string &temp)
    {
        while(i<=j)
        {
            if(temp[i]!=temp[j])
            return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    string find(string &s,int i,int j,vector<vector<int>>&dp,string answer)
    {
       
       if(dp[i][j]!=-1) return answer;
       bool ans=true;
     // =isPalindrom(i,j,s);

        int i1=i;
        int j1=j;
        while(i1<=j1)
        {
            if(s[i1]!=s[j1])
            {
            ans= false;
            break;
            }
            else
            {
                i1++;
                j1--;
            }
        }
       if(ans)
       {
        string temp="";
        for(int l=i;l<=j;l++)
        {
            temp+=s[l];
        }
        answer=temp;
         dp[i][j]= 1;
         return answer;
       }
       string t1=find(s,i+1,j,dp,answer);
       string t2=find(s,i,j-1,dp,answer);


        
    dp[i][j]=1;

       return answer= t1.length()>t2.length()?t1:t2;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        //vector<vector<int>>dp(n,vector<int>(n,-1));
        //return find(s,0,n-1,dp,"");
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        int fi=0,len=1;
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n;i++)
            {
                int j=i,k=i+l-1;
                if(k>=n) break;
                if(l==2 && s[j]==s[k])
                {
                    
                        fi=j;
                        len=l;
                    
                    dp[j][k]=1;
                }
                else if(s[j]==s[k])
                {
                    if(dp[j+1][k-1]==1)
                    {
                        dp[j][k]=1;
                        if(len<l)
                        {
                            fi=j;
                            len=l;
                        }
                    }
                    else
                    {
                        dp[j][k]=0;
                    }
                }
            }
        }
        return s.substr(fi,len);
    }
};