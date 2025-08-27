//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  bool dfs(vector<vector<int>>&adj,int node,int V,int par,vector<int>&vis)
  {
         vis[node]=1;
         for(auto it : adj[node])
         {
             if(!vis[it])
             {
                 bool ans=dfs(adj,it,V,node,vis);
                 if(ans) return true;
             }
             else if(it!=par)
             {
                 return true;
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
         vector<int>vis(V,0);
         for(int i=0;i<V;i++)
         {
             if(!vis[i])
             {
                 bool ans=dfs(adj,i,V,-1,vis);
                 if(ans==true) return true;
             }
         }
         
         return false;
         
         
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends