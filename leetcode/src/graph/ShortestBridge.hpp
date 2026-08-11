#pragma once
#include <vector>
#include <queue>
using namespace std;

// 934. Shortest Bridge
// O(n^2) time, O(n^2) space
class ShortestBridge {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        bool found = false;

        // DFS to mark first island as 2 and collect boundary
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n && !found; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, n, q);
                    found = true;
                }
            }
        }

        // Multi-source BFS from first island boundary until hitting second island
        int dirs[] = {0,1,0,-1,0};
        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (int d = 0; d < 4; d++) {
                    int nx = x + dirs[d], ny = y + dirs[d+1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] == 2)
                        continue;
                    if (grid[nx][ny] == 1) return steps;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
            steps++;
        }
        return -1;
    }

private:
    void dfs(vector<vector<int>>& grid, int i, int j, int n, queue<pair<int,int>>& q) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] != 1) return;
        grid[i][j] = 2;
        q.push({i, j});
        dfs(grid, i+1, j, n, q);
        dfs(grid, i-1, j, n, q);
        dfs(grid, i, j+1, n, q);
        dfs(grid, i, j-1, n, q);
    }
};
