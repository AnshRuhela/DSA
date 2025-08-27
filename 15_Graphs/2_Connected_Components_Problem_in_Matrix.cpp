

class Solution {
  public:
  void dfs(vector<int>&lst,vector<vector<int>>&adj,int node,vector<int>&vis)
  {
      vis[node]=1;
      lst.push_back(node);
      for(auto neigh : adj[node])
      {
          if(!vis[neigh])
          {
              dfs(lst,adj,neigh,vis);
          }
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        int n=edges.size();
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<vector<int>>ans;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            vector<int>lst;
            if(!vis[i])
            {
                dfs(lst,adj,i,vis);
                ans.push_back(lst);
            }
        }
        return ans;
    }
};
