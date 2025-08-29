class Solution {
public:
    int find(vector<int>&nums,int ind,int prev,vector<vector<int>>&dp)
    {   
         if(ind==nums.size()) return 0;
         if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
         int nt=find(nums,ind+1,prev,dp);
         int take=INT_MIN;
         if(prev==-1||nums[prev]<nums[ind])
         {
             take=1+find(nums,ind+1,ind,dp);   
         }
         return dp[ind][prev+1]= max(take,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
         return find(nums,0,-1,dp);
    }
};