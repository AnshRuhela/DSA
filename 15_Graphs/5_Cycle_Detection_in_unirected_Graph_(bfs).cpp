
class Solution {
  public:
  
  bool bfs(vector<vector<int>>&adj,int node,int V)
  {
         vector<int>vis(V,0);
         vector<int>par(V,-1);
         queue<int>q;
         q.push(node);
         vis[node]=1;
         while(!q.empty())
         {
             int top=q.front();
             q.pop();
             for(auto it : adj[top])
             {
                 if(vis[it]==1 && par[top]!=it)
                 {
                     return true;
                 }
                     if(!vis[it])
                     {
                         q.push(it);
                         vis[it]=1;
                         par[it]=top;
                     }
                 
             }
         }
         return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
         int e=edges.size();
         vector<vector<int>>adj(V);
         for(int i=0;i<e;i++)
         {
             int u=edges[i][0];
             int v=edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
         
         for(int i=0;i<V;i++)
         {
             bool ans=bfs(adj,i,V);
             if(ans==true) return true;
         }
         
         return false;
         
         
    }
};