// code is similar to q41 but a difference is condition and sorting the array.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        int lastInd=0;
        int longestDivisibleSub=1;
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(longestDivisibleSub<dp[i])
            {
                longestDivisibleSub=dp[i];
                lastInd=i;
            }
        }

        vector<int>ans(longestDivisibleSub);
        int i=longestDivisibleSub-1;
        while(i>=0)
        {
            ans[i]=nums[lastInd];
            lastInd=hash[lastInd];
            i--;
        }
        return ans;
    }
};