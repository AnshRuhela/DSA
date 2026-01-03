/*
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
*/

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
