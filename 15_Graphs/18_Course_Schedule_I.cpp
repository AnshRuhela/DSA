class Solution {
public:
    bool isCycle(int i,vector<int>&vis,vector<vector<int>>&adj,vector<int>&dfsvis)
    {
        vis[i]=1;
        dfsvis[i]=1;
        for(auto it : adj[i])
        {
            if(!vis[it])
            {
                bool cycle= isCycle(it,vis,adj,dfsvis);
                if(cycle) return true;
            }
            else if(dfsvis[it]==1)
            {
                    return true;   
            }
        }
        dfsvis[i]=0;
        return false;
    }

    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
        }
        vector<int>vis(numCourses,0);
        vector<int>dfsvis(numCourses,0);
        for(int i=0;i<n;i++)
        {
            int node=prerequisites[i][1];
            if(!vis[node])
            {
                if(isCycle(node,vis,adj,dfsvis))
                return false;
            }
        }



        return true;
    }
};