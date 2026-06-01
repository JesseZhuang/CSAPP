#ifndef LEETCODE_SHORTESTPATHBINARYMATRIX_HPP
#define LEETCODE_SHORTESTPATHBINARYMATRIX_HPP

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// LeetCode 1091 - Shortest Path in Binary Matrix
class Solution1091 {
public:
    // BFS approach: O(n^2) time, O(n^2) space
    static int bfs(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1; // blocked
        if (n == 1) return 1; // single cell

        // 8 directions (including diagonals)
        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // mark visited by storing distance

        while (!q.empty()) {
            auto [r, c] = q.front(); // current cell
            q.pop();
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue; // bounds check
                if (grid[nr][nc] != 0) continue; // already visited or blocked
                grid[nr][nc] = grid[r][c] + 1; // distance from start
                if (nr == n - 1 && nc == n - 1) return grid[nr][nc]; // reached goal
                q.push({nr, nc});
            }
        }
        return -1; // no path found
    }

    // A* approach with Chebyshev distance heuristic: O(n^2 log n) time, O(n^2) space
    static int aStar(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1; // blocked
        if (n == 1) return 1; // single cell

        int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        // Chebyshev distance heuristic (admissible for 8-directional movement)
        auto h = [&](int r, int c) { return max(n - 1 - r, n - 1 - c); };

        // dist[r][c] = shortest known distance from start
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;

        // priority queue: (f = g + h, row, col)
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({1 + h(0, 0), 0, 0}); // f-value, row, col

        while (!pq.empty()) {
            auto [f, r, c] = pq.top(); // lowest f-value node
            pq.pop();

            if (r == n - 1 && c == n - 1) return dist[r][c]; // reached goal

            // Skip if we already found a better path to this node
            if (dist[r][c] + h(r, c) < f) continue;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue; // bounds
                if (grid[nr][nc] != 0) continue; // blocked
                int newDist = dist[r][c] + 1; // uniform edge cost
                if (newDist < dist[nr][nc]) { // found shorter path
                    dist[nr][nc] = newDist;
                    pq.push({newDist + h(nr, nc), nr, nc}); // enqueue with f-value
                }
            }
        }
        return -1; // no path found
    }
};

#endif //LEETCODE_SHORTESTPATHBINARYMATRIX_HPP
