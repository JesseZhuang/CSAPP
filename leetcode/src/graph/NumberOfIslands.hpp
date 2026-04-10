#ifndef LEETCODE_NUMBEROFISLANDS_HPP
#define LEETCODE_NUMBEROFISLANDS_HPP

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // DFS approach: mark visited cells by flipping '1' -> '0'.
    // Time: O(m*n), Space: O(m*n) worst-case recursion depth.
    int numIslandsDFS(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    dfs(grid, i, j, m, n);
                    count++;
                }
        return count;
    }

    // BFS approach: mark visited cells by flipping '1' -> '0'.
    // Time: O(m*n), Space: O(min(m,n)) queue size bounded by shorter dimension.
    int numIslandsBFS(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    bfs(grid, i, j, m, n);
                    count++;
                }
        return count;
    }

private:
    void dfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }

    void bfs(vector<vector<char>> &grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        grid[i][j] = '0';
        q.push({i, j});
        int dirs[] = {0, 1, 0, -1, 0};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d], nc = c + dirs[d + 1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }
};

#endif //LEETCODE_NUMBEROFISLANDS_HPP
