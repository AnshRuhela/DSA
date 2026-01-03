/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Example 1:

Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:

Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 
*/
class Solution {
public:
    // this is also can be done by dijkstras algo by taking matrix of dist
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1|| grid[n-1][n-1] == 1){
            return -1;
        }
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        vis[0][0] = 1;
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int r = top.first.first;
            int c = top.first.second;
            int wt = top.second;
            if(r == n-1 && c == n-1){
                return wt;
            }
            int drow[] = {1,1,1,-1,-1,-1,0,0};
            int dcol[]  {1,0,-1,1,0,-1,-1,1};
            for(int i = 0; i<8; i++){
                int nrow = drow[i] + r;
                int ncol = dcol[i] + c;
                if(nrow >=0 && nrow <n && ncol >=0 && ncol <n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 0){
                    q.push({{nrow,ncol},wt+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
};
