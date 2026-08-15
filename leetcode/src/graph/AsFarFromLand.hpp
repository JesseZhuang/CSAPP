#ifndef LEETCODE_ASFARFROMLAND_HPP
#define LEETCODE_ASFARFROMLAND_HPP

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// leet 1162, multi-source BFS. O(n^2) time, O(n^2) space.
class Solution1162BFS {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        // Enqueue all land cells, mark water as unvisited (-1)
        for (int i = 0; i < n; i++) {          // O(n^2) initialization
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
                else
                    grid[i][j] = -1;
            }
        }
        // Edge case: no land or no water
        if (q.empty() || (int)q.size() == n * n) return -1;

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int dist = -1;
        // BFS level by level — each cell visited at most once: O(n^2)
        while (!q.empty()) {
            int sz = q.size();
            dist++;
            for (int k = 0; k < sz; k++) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == -1) {
                        grid[nx][ny] = dist + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return dist;
    }
};

// leet 1162, DP two passes. O(n^2) time, O(1) extra space (in-place).
class Solution1162 {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int INF = 2 * n; // upper bound on any Manhattan distance in grid

        // First pass (top-left to bottom-right): O(n^2)
        // land cells → 0, water cells → min(top, left) + 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = INF;
                    if (i > 0) grid[i][j] = min(grid[i][j], grid[i-1][j] + 1);
                    if (j > 0) grid[i][j] = min(grid[i][j], grid[i][j-1] + 1);
                }
            }
        }

        int ans = 0;
        // Second pass (bottom-right to top-left): O(n^2)
        // refine with bottom+1 and right+1, track max
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < n - 1) grid[i][j] = min(grid[i][j], grid[i+1][j] + 1);
                if (j < n - 1) grid[i][j] = min(grid[i][j], grid[i][j+1] + 1);
                ans = max(ans, grid[i][j]);
            }
        }

        // If ans is 0 (all land) or INF (all water), return -1
        return (ans == 0 || ans >= INF) ? -1 : ans;
    }
};

#endif
