/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 
*/

class Solution {
public:
    int find(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int forw=0;
        if(j+1<n && grid[i][j+1]==0)
        {
             forw=find(grid,i,j+1,m,n,dp);
        }
        int down=0;
        if(i+1<m &&  grid[i+1][j]==0)
        {
             down=find(grid,i+1,j,m,n,dp);
        }
        return dp[i][j]=forw+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        //vector<vector<int>>dp(m,vector<int>(n,-1));
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        //return find(obstacleGrid,0,0,m,n,dp);


         vector<vector< long long>>dp(m,vector< long long>(n,0));
            dp[m-1][n-1]=1;

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1) continue;
                 long long forw=0;
                if(j+1<n && obstacleGrid[i][j+1]==0)
                {
                    forw=dp[i][j+1];
                }
                long long down=0;
                if(i+1<m &&  obstacleGrid[i+1][j]==0)
                {
                    down=dp[i+1][j];
                }
                dp[i][j]=forw+down;
            }
        }    

        return dp[0][0];


    }
};