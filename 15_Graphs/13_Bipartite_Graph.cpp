#include <bits/stdc++.h>
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        queue<int> q;
        int fl = 0;
        for (int i = 0; i < graph.size(); i++) {
            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
            }
                while (!q.empty()) {
                    int i = q.front();
                    q.pop();
                    for (auto it : graph[i]) {
                            if (vis[i] == 1) {
                                if (vis[it] == 0) {
                                    vis[it] = 2;
                                    q.push(it);
                                } else if (vis[it] == 1) {
                                    return false;
                                }
                            } else {
                                if (vis[it] == 0) {
                                    vis[it] = 1;
                                    q.push(it);
                                } else if (vis[it] == 2)
                                    return false;
                            }
                    }
                }
        }
        return true;
    }
};