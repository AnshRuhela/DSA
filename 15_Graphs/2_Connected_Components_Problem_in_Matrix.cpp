/*
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented as a 2D array edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v.

Your task is to return a list of all connected components. Each connected component should be represented as a list of its vertices, with all components returned in a collection where each component is listed separately.

Note: You can return the components in any order, driver code will print the components in sorted order.

Examples :

Input: V = 5, edges[][] = [[0, 1], [2, 1], [3, 4]]
Output: [[0, 1, 2], [3, 4]]
Explanation:

Input: V = 7, edges[][] = [[0, 1], [6, 0], [2, 4], [2, 3], [3, 4]]
Output: [[0, 1, 6], [2, 3, 4], [5]]
Explanation:

*/

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
