class Solution {
public:
    bool topo(int i,vector<int>&dfsvis,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans,stack<int>&st)
    {
        dfsvis[i]=1;
        vis[i]=1;

        for(auto it : adj[i])
        {
            if(!vis[it])
            {
                bool cycle=topo(it,dfsvis,adj,vis,ans,st);
                if(cycle) return true;
            }
            else if(dfsvis[it]==1)
            {
                return true;
            }
        }
        st.push(i);
        dfsvis[i]=0;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<int>ans1;
        if(n==0) {
            for(int i=0;i<numCourses;i++)
            {
                ans1.push_back(i);
            }
            return ans1;
        }

        vector<vector<int>>adj(numCourses);

        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int>ans;
        vector<int>vis(numCourses,0);
        vector<int>dfsvis(numCourses,0);
        stack<int>st;
        for(int i=0;i<numCourses;i++)
        {
            // int node=prerequisites[i][0];
            if(!vis[i])
            {
                bool cycle=topo(i,dfsvis,adj,vis,ans,st);
                if(cycle) return {};
            }
        }

        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};