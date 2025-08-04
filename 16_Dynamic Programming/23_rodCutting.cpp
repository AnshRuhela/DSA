// below is the solution in 1d dp.
class Solution {
  public:
    int find(int n,vector<int>&price,vector<int>&dp)
    {
        if(n==0)
        {
            return 0;
        }
        
        if(dp[n]!=-1) return dp[n];
        int ans=-1e8;
        for(int i=1;i<=price.size();i++)
        {
            if(n-(i)>=0)
            {
                ans=max(ans,(price[i-1]+find(n-(i),price,dp)));
            }
        }
        return dp[n]= ans;
    }
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<int>dp(n+1,-1);
        return find(n,price,dp);
        
    }
};

// below is the solution in 2d dp.
class Solution {
  public:
    int find(int ind , int len , vector<int> &price , vector<vector<int>> &dp){
        if(len == 0) return 0;
        if(ind == 0){ // means cut the rod in length 1
            return len * price[ind];
        }
        
        if(dp[ind][len] != -1) return dp[ind][len];
        int ntake = find(ind-1,len,price,dp);
        int take = INT_MIN;
        if(len>=ind+1){
            take = price[ind] + find(ind,len - (ind+1) , price,dp);
        }
        return dp[ind][len] = max(ntake,take);
        
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        int len = n;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return find(n-1,len,price,dp);
    }
};