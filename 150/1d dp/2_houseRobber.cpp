class Solution {
public:
    int find(vector<int>&nums,int n,int ind,vector<int>&dp)
    {
        if(ind==0) return nums[ind];
        if(ind==1) return max(nums[ind],nums[ind-1]);
        if(dp[ind]!=-1) return dp[ind];
        int nt=find(nums,n,ind-1,dp);
        int take=nums[ind]+find(nums,n,ind-2,dp);
        return dp[ind]= max(take,nt);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // return find(nums,n,n-1,dp);

        if(n>=1) dp[0]=nums[0];
        if(n>=2) dp[1]=max(nums[0],nums[1]);

        for(int ind=2;ind<n;ind++)
        {
            int nt=dp[ind-1];
            int take=nums[ind]+dp[ind-2];
            dp[ind]= max(take,nt);
        }
        return dp[n-1];
    }
};