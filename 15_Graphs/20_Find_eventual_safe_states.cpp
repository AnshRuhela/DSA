

// TOPO SORT (KAHN'S ALGO) LOGIC

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<vector<int>>ngraph(v);
        for(int i=0;i<v;i++)
        {
            for(auto it : graph[i])
            {
                ngraph[it].push_back(i); // graph reverse kar diya.       
            }
        }
        vector<int>indegree(v,0);
        for(auto it : ngraph)
        {
            for(auto i : it)
            {
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(auto it : ngraph[top])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

/*


// DFS LOGIC


class Solution {
public:
    bool dfs(int node,vector<int>&vis,vector<int>&dfsvis,vector<vector<int>>&graph,vector<int>&safe)
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto neigh : graph[node])
        {
           if(!vis[neigh])
           {
                
                bool check=dfs(neigh,vis,dfsvis,graph,safe);
                if(check)
                {
                    safe[node]=0; // agar cycle mili vo safe node nahi ho sakti.
                    return true;
                }
           }
           else if(dfsvis[neigh])
           {
                safe[node]=0; // ye wali node bhi safe node nahi ho sakti.
                return true;
           }
        }
        safe[node]=1; // agar kisi node ke liye poora dfs run hogya then it a safe node.
        dfsvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>vis(v,0);
        vector<int>dfsvis(v,0);
        vector<int>safe(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,dfsvis,graph,safe);
            }
        }
        vector<int>ans;
        for(int i=0;i<v;i++)
        {
            if(safe[i]==1)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

*/
