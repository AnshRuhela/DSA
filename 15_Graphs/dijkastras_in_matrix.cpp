#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> Node; 
// {distance, {row, col}}

int dijkstraGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Directions: up, right, down, left
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // Start from (0,0)
    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], {0, 0}});

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int currDist = top.first;
        int r = top.second.first;
        int c = top.second.second;

        // Skip outdated entries
        if (currDist > dist[r][c]) continue;

        // Explore 4 directions
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                int newDist = currDist + grid[nr][nc];

                if (newDist < dist[nr][nc]) {
                    dist[nr][nc] = newDist;
                    pq.push({newDist, {nr, nc}});
                }
            }
        }
    }

    return dist[n-1][m-1];  // destination
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {6, 5, 1},
        {4, 2, 1}
    };

    cout << "Minimum cost path = " << dijkstraGrid(grid);
    return 0;
}