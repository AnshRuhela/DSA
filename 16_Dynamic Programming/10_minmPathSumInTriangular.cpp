/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
*/


class Solution {
public:
    int find(int row , int i , vector<vector<int>>& triangle , vector<vector<int>> &dp){
        if(row==triangle.size()) return 0;
        if(dp[row][i] != -1){
            return dp[row][i];
        }
        int take_i = triangle[row][i] + find(row+1,i,triangle,dp);
        int take_ii = INT_MAX;
        if(i+1<triangle[row].size()){  
            take_ii = triangle[row][i+1] + find(row+1,i+1,triangle,dp);
        }
        return dp[row][i] = min(take_i , take_ii);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int max_col = triangle[r-1].size();
        // vector<vector<int>> dp(r,vector<int> (max_col,-1)); // this dp is for memoization
        vector<vector<int>> dp(r+1,vector<int> (max_col,0)); // this dp is for tabulation
        for(int row = r-1; row>=0; row--){
            for(int i = row; i>=0; i--){
                int take_i = triangle[row][i] + dp[row+1][i];
                int take_ii = INT_MAX;
                if(i+1<triangle[row].size()){
                    take_ii = triangle[row][i+1] + dp[row+1][i+1];
                }
                dp[row][i] = min(take_i , take_ii);
            }
        }
        // return find(0,0,triangle , dp);
        return dp[0][0];
    }
};