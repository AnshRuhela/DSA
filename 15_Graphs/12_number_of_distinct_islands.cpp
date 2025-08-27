
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,set<vector<pair<int,int>>>&st,int r,int c,int m,int n,vector<pair<int,int>>&temp,pair<int,int>&base)
    {
            
            vis[r][c]=1;
            temp.push_back({r-base.first,c-base.second});
            int delr[]={0,1,0,-1};
            int delc[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int row=delr[i]+r;
                int col=delc[i]+c;
                if(row>=0 && row<m && col>=0 && col<n && vis[row][col]==0 && grid[row][col]==1)
                {
                    dfs(grid,vis,st,row,col,m,n,temp,base);
                }
            }
        }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        set<vector<pair<int,int>>>st;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>>temp;
                    pair<int,int>base={i,j};
                    dfs(grid,vis,st,i,j,m,n,temp,base);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};
