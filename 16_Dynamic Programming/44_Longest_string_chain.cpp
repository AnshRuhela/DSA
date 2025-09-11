class Solution {
public:

    bool compare(string &s1,string &s2)
    {
        int n1=s1.length();
        int n2=s2.length();

        if(n1+1!=n2) return false; // agar ek character ka difference hoga tabhi karna hai compare.
        int i=0,j=0;
        while(j<n2)
        {
            if(s1[i]==s2[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return (i==n1 && j==n2); // means last me dono pointer last me hone chahiye.
    }
   static bool comp(string &s1,string &s2)
    {
        return s1.length()<s2.length();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<int>dp(n,1);
        int maxi=1;
        sort(words.begin(),words.end(),comp);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(compare(words[j],words[i]) && dp[j]+1>dp[i]) // compare means is words[j]+1char =words[i]
                {
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};