/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        for(auto it : flights)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({-1,{src,0}});
        int ans=INT_MAX;
        while(!q.empty())
        {
            auto top=q.front();
            q.pop();
            int step=top.first;
            int node=top.second.first;
            int wt=top.second.second;
            if(step>k)
            {
                break;
            }
            if(step<=k)
            {
                if(node==dst)
                {
                    ans=min(ans,wt);  
                } 
            }
            for(auto it : adj[node])
            {
                int node2=it.first;
                int wt2=it.second;
                if(wt+wt2<dist[node2])
                {
                    q.push({step+1,{node2,wt+wt2}});
                    dist[node2]=wt+wt2;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};