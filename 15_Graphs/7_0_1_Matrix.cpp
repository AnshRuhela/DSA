class Solution {
public:
    int bfs(vector<vector<int>>&mat,int i,int j,int m,int n)
    {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{i,j}});
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[i][j]=1;
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();

            int dist=top.first;
            int u=top.second.first;
            int v=top.second.second;
            int delr[]={0,1,0,-1};
            int delc[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int row=delr[i]+u;
                int col=delc[i]+v;
                if(row>=0 && row<m && col>=0 && col < n && mat[row][col]==0 && vis[row][col]==0)
                {
                    return dist+1;
                }
                else if(row>=0 && row<m && col>=0 && col < n && vis[row][col]==0)
                {
                    q.push({dist+1,{row,col}});
                    vis[row][col]=1;
                }
            }
        }
        return 0;// dummy.
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            int dist=top.first;
            int u=top.second.first;
            int v=top.second.second;
            ans[u][v]=dist;
            int delr[]={0,1,0,-1};
            int delc[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int row=delr[i]+u;
                int col=delc[i]+v;
                if(row>=0 && row<m && col>=0 && col < n && vis[row][col]==0)
                {
                    q.push({dist+1,{row,col}});
                    vis[row][col]=1;
                }
            }
        }
        return ans;
    }
};