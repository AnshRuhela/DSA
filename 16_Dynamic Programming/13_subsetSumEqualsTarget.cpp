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
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        //  vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        //  return find(n-1 , arr,sum,dp);
        
        vector<vector<int>> dp(n,vector<int>(sum+1,false));
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
        return dp[n-1][sum];
       
    }
};