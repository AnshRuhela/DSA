class Solution {
public:
    bool find(int i,int j,string &s,string &p,vector<vector<int>>&dp)
    {
        if(i<0 && j<0) return true;
        if(j<0) return false; // p wali exhaust hogyi hai and s nahi hui hai means not possible
        if(i<0) // agar s exhaust hogyi then p wali me sirf * hone chahiye tabhi true return hoga.
        {
            while(j>=0)
            {
                if(p[j]!='*')
                {
                    return false;
                }
                j--;
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?')
        {
            return dp[i][j]= find(i-1,j-1,s,p,dp); // jab match hoga ya p[j]=='?' hona chahiye
        }
        if(p[j]=='*')
        {
            return dp[i][j]= find(i-1,j,s,p,dp) || find(i,j-1,s,p,dp); // ya to * ko match krado ya usko empty consider kro.
        }
        return dp[i][j]= false; // agar ek single character bhi mismatch kiya so return false.
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return find(m-1,n-1,s,p,dp);
    }
};