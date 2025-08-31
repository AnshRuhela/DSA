// we have 4 approches to solve the problem 1.memoization 2. tabulation 3. space optimization and 4. optimal.



class Solution {
public:
// 1.memoization
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
        int n=nums.size();
        // vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        //  return find(nums,0,-1,dp);
// 2. tabulation
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prev=ind-1;prev>=-1;prev--)
            {
                 int nt=dp[ind+1][prev+1]; // we are considering second parameter in +1 state. 
                int take=INT_MIN;
                if(prev==-1||nums[prev]<nums[ind])
                {
                    take=1+dp[ind+1][ind+1];   // remember to take second parameter in +1 state.
                }
                dp[ind][prev+1]= max(take,nt);
            }
        }
        return dp[0][0]; // we actualy have to return dp[0][-1] but we take the second parameter in +1 state so we returned dp[0][-1+1]

    }
};\


//3 space optimization not done yet.

//4 optimal.

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};