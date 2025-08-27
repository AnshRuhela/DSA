class Solution {
public:
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int r,int c,int m,int n)
    {
        vis[r][c]=1;
        int delr[] = {0,1,0,-1};
        int delc[] = {-1,0,1,0};
        for(int i = 0; i<4; i++){
            int nrow = r + delr[i];
            int ncol = c + delc[i];
            if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && vis[nrow][ncol]==false && grid[nrow][ncol]==1){
                dfs(grid,vis,nrow,ncol,m,n);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==1 && (i==0 || i==m-1 || j==0 || j==n-1))
                {
                    dfs(grid,vis,i,j,m,n);
                }
            }
        }

        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};  