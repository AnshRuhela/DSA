int longestBitonicSubsequence(vector<int>& nums, int n)
{
	vector<int>dp1(n,1),dp2(n,1);

    // finding LIS from left to right
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp1[j]+1>dp1[i])
                {
                    dp1[i]=dp1[j]+1;
                }
            }
        }
        // finding LIS from right to left.
        for(int i=n-2;i>=0;i--)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]<nums[i] && dp2[j]+1>dp2[i])
                {
                    dp2[i]=dp2[j]+1;
                }
            }
        }
        
        // finding longest bitonic subsequence.
        int ans=1;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
        return ans;
}
