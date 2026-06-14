#ifndef LEETCODE_MAXAREAOFISLAND_HPP
#define LEETCODE_MAXAREAOFISLAND_HPP

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class MaxAreaOfIslandSolution {
public:
    // DFS approach: for each unvisited 1, compute area recursively, track max.
    // Time: O(m*n), Space: O(m*n) worst-case recursion depth.
    int maxAreaOfIslandDFS(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; i++)        // O(m)
            for (int j = 0; j < n; j++)    // O(n)
                if (grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j, m, n));
        return res;
    }

    // BFS approach: for each unvisited 1, compute area via queue, track max.
    // Time: O(m*n), Space: O(min(m,n)) queue size.
    int maxAreaOfIslandBFS(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        int dirs[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++)        // O(m)
            for (int j = 0; j < n; j++)    // O(n)
                if (grid[i][j] == 1) {
                    int area = 0;
                    queue<pair<int, int>> q;
                    grid[i][j] = 0;
                    q.push({i, j});
                    while (!q.empty()) {   // O(m*n) total across all calls
                        auto [r, c] = q.front();
                        q.pop();
                        area++;
                        for (int d = 0; d < 4; d++) {
                            int nr = r + dirs[d], nc = c + dirs[d + 1];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                            }
                        }
                    }
                    res = max(res, area);
                }
        return res;
    }

private:
    int dfs(vector<vector<int>> &grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1) return 0;
        grid[i][j] = 0;
        return 1 + dfs(grid, i + 1, j, m, n) + dfs(grid, i - 1, j, m, n)
                 + dfs(grid, i, j + 1, m, n) + dfs(grid, i, j - 1, m, n);
    }
};

#endif //LEETCODE_MAXAREAOFISLAND_HPP
