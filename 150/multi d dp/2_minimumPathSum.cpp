class Solution {
public:
    int find(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return dp[i][j]=grid[i][j]; //base case.
        if(i==m-1 && j!=n-1) return dp[i][j]=grid[i][j]+find(grid,i,j+1,m,n,dp); // agar colm khatam hogye then neeche chalna suru karo. 
        if(i!=m-1 && j==n-1) return dp[i][j]=grid[i][j]+find(grid,i+1,j,m,n,dp); // agar row khatam hogye then front me chalna suru karo.

        int forw=grid[i][j]+find(grid,i,j+1,m,n,dp);
        int down=grid[i][j]+find(grid,i+1,j,m,n,dp);
        return dp[i][j]= min(forw,down); 
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,1e8)); // dp array for tabulation and for memoization could be different.
        //return find(grid,0,0,m,n,dp);
        dp[m-1][n]=0;
        dp[m][n-1]=0;


        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==0 && j!=0)  dp[i][j]=grid[i][j]+dp[i][j+1];
                if(i!=0 && j==0)  dp[i][j]=grid[i][j]+dp[i+1][j];
                if(i==0 && j==0)  dp[i][j]=grid[i][j];
                int forw=grid[i][j]+dp[i][j+1];
                int down=grid[i][j]+dp[i+1][j];
                dp[i][j]= min(forw,down); 
            }
        }
        return dp[0][0];
    }
};