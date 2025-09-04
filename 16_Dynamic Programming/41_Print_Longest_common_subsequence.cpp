class Solution {
  public:
    vector<int> getLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        int lastIndex=0;
        int LIS=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(arr[i]>arr[j])
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=dp[j]+1;
                        hash[i]=j;
                    }
                }
            }
            if(dp[i]>LIS)
            {
                LIS=dp[i];
                lastIndex=i; // we tracked the last index updated which is the maximum bcs. last wali maximum index se hi hume backtrack start karna hai.
            }
        }
        vector<int>res(LIS);
        int i=LIS-1;
        while(i>=0) // jabtak saari index fill nahi ho jaati.
        {
            res[i]=arr[lastIndex];
            lastIndex=hash[lastIndex];
            i--;
        }
        return res;
    }
};