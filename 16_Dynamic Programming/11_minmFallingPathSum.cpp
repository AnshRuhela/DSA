class Solution {
public:
    int find(vector<vector<int>>&matrix,int row,int col,int n,vector<vector<int>>&dp)
    {
        if(row==n)
        {
            return 0;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int ans1=1e8,ans2=1e8,ans3=1e8;
        if(row<n)
        {
            ans1=matrix[row][col]+find(matrix,row+1,col,n,dp);
        }
        
        if(row<n && col<n-1)
        {
            ans2=matrix[row][col]+find(matrix,row+1,col+1,n,dp);
        }
        
        if(row<n && col>0)
        {
            ans3=matrix[row][col]+find(matrix,row+1,col-1,n,dp);
        }
        return dp[row][col]= min(ans1,min(ans2,ans3));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=1e8;
        int n=matrix.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // for(int i=0;i<n;i++)
        // {
        //     ans=min(ans,find(matrix,0,i,n,dp));
        // }

        vector<vector<int>>dp(n+1,vector<int>(n,0)); // made n+1 for tabulation so that base case bhi handle ho jaye.

        
            for(int row=n-1;row>=0;row--)
            {
                for(int col=n-1;col>=0;col--)
                {
                    int ans1=1e8,ans2=1e8,ans3=1e8;
                    if(row<n)
                    {
                        ans1=matrix[row][col]+dp[row+1][col];
                    }
                    
                    if(row<n && col<n-1)
                    {
                        ans2=matrix[row][col]+dp[row+1][col+1];
                    }
                    
                    if(row<n && col>0)
                    {
                        ans3=matrix[row][col]+dp[row+1][col-1];
                    }

                    dp[row][col]=min(ans1,min(ans2,ans3));
                }
            }
        for(int i=0;i<n;i++) // dp ki pehli row se ans calculate hoga.
            {
                
                ans=min(ans,dp[0][i]);
            }

      return ans;
    }
};