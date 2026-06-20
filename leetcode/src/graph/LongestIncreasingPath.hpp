#pragma once
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class LongestIncreasingPathSolution {
    int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        if (memo[i][j] != 0) return memo[i][j]; // O(1) memo lookup
        int m = matrix.size(), n = matrix[0].size();
        int best = 1;
        for (auto& d : dirs) {
            int ni = i + d[0], nj = j + d[1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] > matrix[i][j]) {
                best = max(best, 1 + dfs(matrix, memo, ni, nj)); // O(m*n) total DFS calls
            }
        }
        return memo[i][j] = best;
    }

public:
    // DFS + memoization. Time O(m*n), Space O(m*n).
    int longestIncreasingPathDFS(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0)); // O(m*n) space
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(matrix, memo, i, j)); // each cell visited once due to memo
        return ans;
    }

    // Topological sort BFS (Kahn's algorithm). Time O(m*n), Space O(m*n).
    int longestIncreasingPathBFS(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0)); // O(m*n) space

        // Build indegree: count neighbors smaller than current cell
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (auto& d : dirs) {
                    int ni = i + d[0], nj = j + d[1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] < matrix[i][j])
                        indegree[i][j]++; // edge from smaller neighbor to this cell
                }

        queue<pair<int,int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (indegree[i][j] == 0)
                    q.push({i, j}); // start BFS from local minima

        int layers = 0;
        while (!q.empty()) {
            int sz = q.size();
            layers++; // each BFS layer = one step in longest path
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] > matrix[x][y]) {
                        if (--indegree[nx][ny] == 0) // O(m*n) total edge relaxations
                            q.push({nx, ny});
                    }
                }
            }
        }
        return layers;
    }
};
