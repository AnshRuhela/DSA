class Solution {
public:
    void dfs(vector<vector<int>>&ans,int sr,int sc,int color,int m,int n,int prev)
    {
        ans[sr][sc]=color;
        int delr[]={0,1,0,-1};
        int delc[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int row=delr[i]+sr;
            int col=delc[i]+sc;
            if(row>=0 && row<m && col>=0 && col<n && ans[row][col]==prev && ans[row][col]!=color)
            {
                dfs(ans,row,col,color,m,n,prev);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int m=ans.size();
        int n=ans[0].size();
        int prev=image[sr][sc];
        dfs(ans,sr,sc,color,m,n,prev);
        return ans;
    }
};