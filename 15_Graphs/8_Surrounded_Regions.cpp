/*
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:


In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]
*/
class Solution {
public:
    void dfs(int r , int c, int n1 , int n2, vector<vector<char>>& board , vector<vector<bool>> &vis){
        vis[r][c]=true;
        int delr[] = {0,1,0,-1};
        int delc[] = {-1,0,1,0};
        for(int i = 0; i<4; i++){
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            if(nrow<n1 && nrow>=0 && ncol<n2 && ncol>=0 && board[nrow][ncol]=='O' && vis[nrow][ncol]==false){
                dfs(nrow,ncol,n1,n2,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n1 = board.size();
        int n2 = board[0].size();
        vector<vector<bool>> vis(n1,vector<bool>(n2,false));
        bool check=false;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                // Check boundary conditions (first row, last row, first column, last column)
                if (board[i][j] == 'O' && (i == 0 || i == n1 - 1 || j == 0 || j == n2 - 1) && vis[i][j]==false) {
                    dfs(i, j,n1,n2,board,vis); // Start DFS from boundary 'O'
                }
            }
        }
        for(int i = 0; i<n1; i++){
            for(int j = 0; j<n2; j++){
                if(vis[i][j]==false)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};