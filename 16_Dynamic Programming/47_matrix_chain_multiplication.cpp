class Solution {
  public:
    int find(vector<int>&arr,int i,int j,vector<vector<int>>&dp)
    {
        if(i==j)
        {
            return 0;
        } 
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        
        for(int k=i;k<j;k++) // no of partition jitne honge utne time loop chalega.
        {
            int steps=(arr[i-1]*arr[k]*arr[j])+find(arr,i,k,dp)+find(arr,k+1,j,dp); // (arr[i-1]*arr[k]*arr[j]) ye no. of steps hai jab ye wali matrix multiply hogi.
            ans=min(ans,steps);
        }
        
        return dp[i][j]= ans;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        // return find(arr,1,n-1,dp);
        
        // tabulation

        for(int i=1;i<n;i++)
        {
            dp[i][i]=0;
        }
        for(int i=n-1;i>0;i--)
        {
            for(int j=i+1;j<n;j++)// j kabhi i se pehle aa hi nahi sakta , so we initialized k =i+1.
            {
                int ans=INT_MAX;
                for(int k=i;k<j;k++)  
                {
                    int steps=(arr[i-1]*arr[k]*arr[j])+dp[i][k]+dp[k+1][j];
                    ans=min(ans,steps);
                }
                dp[i][j]= ans;
            }
        }
        return dp[1][n-1];
    }
};