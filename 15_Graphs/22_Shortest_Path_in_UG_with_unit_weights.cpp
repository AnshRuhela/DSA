class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int v=adj.size();
        vector<int>dist(v,INT_MAX);
        queue<int>q;
        dist[src]=0;
        q.push(src);
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            for(auto it : adj[top])
            {
                if(dist[top]+1<dist[it])
                {
                    dist[it]=dist[top]+1;
                    q.push(it);
                }
            }
        }
        for(int i=0;i<v;i++)
        {
            if(dist[i]==INT_MAX)
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};