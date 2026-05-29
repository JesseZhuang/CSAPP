#ifndef LEETCODE_PACIFICATLANTICWATERFLOW_HPP
#define LEETCODE_PACIFICATLANTICWATERFLOW_HPP

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class PacificAtlanticWaterFlow {
public:
    // DFS approach: start from ocean borders, traverse cells where height >= previous.
    // Two visited matrices. Intersection = answer.
    // Time: O(m*n), Space: O(m*n).
    vector<vector<int>> pacificAtlanticDFS(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, pacific, i, 0, m, n);
            dfs(heights, atlantic, i, n - 1, m, n);
        }
        for (int j = 0; j < n; j++) {
            dfs(heights, pacific, 0, j, m, n);
            dfs(heights, atlantic, m - 1, j, m, n);
        }

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
        return result;
    }

    // BFS approach: same idea with queue.
    // Time: O(m*n), Space: O(m*n).
    vector<vector<int>> pacificAtlanticBFS(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        queue<pair<int, int>> pq, aq;
        for (int i = 0; i < m; i++) {
            pq.push({i, 0}); pacific[i][0] = true;
            aq.push({i, n - 1}); atlantic[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({0, j}); pacific[0][j] = true;
            aq.push({m - 1, j}); atlantic[m - 1][j] = true;
        }

        bfs(heights, pacific, pq, m, n);
        bfs(heights, atlantic, aq, m, n);

        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
        return result;
    }

private:
    int dirs[5] = {0, 1, 0, -1, 0};

    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j, int m, int n) {
        if (visited[i][j]) return;
        visited[i][j] = true;
        for (int d = 0; d < 4; d++) {
            int ni = i + dirs[d], nj = j + dirs[d + 1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && !visited[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, ni, nj, m, n);
            }
        }
    }

    void bfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, queue<pair<int, int>> &q, int m, int n) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d], nc = c + dirs[d + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
};

#endif //LEETCODE_PACIFICATLANTICWATERFLOW_HPP
