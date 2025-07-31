class Solution {
public:
 bool find(int ind , vector<int> &arr , int sum , vector<vector<int>> &dp){
        if(sum==0){
            return true;
        }
        if(ind==0){
            if(arr[0]==sum){
                return true;
            }
            return false;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        bool ntake = find(ind-1,arr,sum,dp);
        bool take = false;
        if(sum>=arr[ind]){
            take = find(ind-1,arr,sum-arr[ind],dp);
        }
        return dp[ind][sum] = (take || ntake);
    }
    bool canPartition(vector<int>& nums) {
           int n = nums.size();
           int sum=0;
           for(auto it : nums)
           {
            sum+=it;
           }
           if(sum%2!=0) return false;
           int target=sum/2;
         vector<vector<int>> dp(n,vector<int>(target+1,-1));
         return find(n-1 , nums,target,dp);
    }
};