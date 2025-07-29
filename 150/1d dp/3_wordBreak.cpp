class Solution {
public:
    int find(string s,vector<string>&wordDict,unordered_set<string>&st,int i,vector<int>&dp)
    {
        if(i==s.length())
        return 1;
        string temp="";
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<s.length();j++)
        {
            temp+=s[j];
            if(st.find(temp)!=st.end())
            {
                int ans=find(s,wordDict,st,j+1,dp);
                if(ans) return dp[i]= 1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        vector<int>dp(s.length(),-1);
        for(int i=0;i<wordDict.size();i++)
        {
            st.insert(wordDict[i]);
        }
        return find(s,wordDict,st,0,dp);
       
    }
};