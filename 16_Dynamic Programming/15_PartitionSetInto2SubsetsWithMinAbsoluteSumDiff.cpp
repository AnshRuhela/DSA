class Solution {

  public:
   vector<vector<bool>>subsetSumLogic(vector<int>&arr,int sum,int n)
    {
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        for(int ind = 0; ind<n; ind++){
            dp[ind][0] = true;
        }
        if (arr[0] <= sum) // out of bound nahi hona chahiye array.
            dp[0][arr[0]] = true;
        
        for(int ind = 1; ind<n; ind++){
            for(int sum1 = 1; sum1<=sum; sum1++){
                bool ntake = dp[ind-1][sum1];
                bool take = false;
                if(sum1>=arr[ind]){
                    take = dp[ind-1][sum1-arr[ind]];
                }
                dp[ind][sum1] = (take || ntake);
            }
        }
        return dp;
    }
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it : nums)
        {
            sum+=it;
        }
        vector<vector<bool>>dp=subsetSumLogic(nums,sum,n); // dp array bna liya poora
        int mini=1e8;
        for(int i=1;i<=sum;i++) // last row me check kiya ki konse possible hai.
        {
            if(dp[n-1][i]==true)
            {
                int s1=i;
                int s2=sum-i; 
                mini=min(mini,abs(s1-s2));
            }
        }
        return mini;
    }
};
