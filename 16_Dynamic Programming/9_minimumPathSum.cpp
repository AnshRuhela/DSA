/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 
*/
class Solution {
public:
    int find(int r , int c , int m , int n , vector<vector<int>>& grid , vector<vector<int>> &dp){

        if(r==m-1 && c==n-1){
            return grid[r][c];
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int move_right = INT_MAX;
            if(c+1<n){// or we can put this base case in top
               move_right =  grid[r][c] + find(r,c+1,m,n,grid,dp);
            }
        int move_down = INT_MAX;
            if(r+1<m){// or we can put this base case in top
                move_down = grid[r][c] + find(r+1,c,m,n,grid,dp);
            }
        return dp[r][c] =  min(move_right,move_down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m,vector<int>(n,-1));
        vector<vector<int>> dp(m,vector<int>(n,-1));

        dp[m-1][n-1] = grid[m-1][n-1];

        for(int r = m-1; r>=0; r--){
            for(int c = n-1; c>=0; c--){

                if(r==m-1 && c==n-1) continue; // this is becasue we have set the value of dp[m-1][n-1];

                int move_right = INT_MAX;
                if(c+1<n){
                    move_right =  grid[r][c] + dp[r][c+1];
                }
                int move_down = INT_MAX;
                if(r+1<m){
                    move_down = grid[r][c] + dp[r+1][c];
                }
            dp[r][c] =  min(move_right,move_down);
            }
        }
        // return find(0,0,m,n,grid,dp);
        return dp[0][0];
    }
};