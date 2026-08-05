#ifndef LEETCODE_SWIMINRISINGWATER_HPP
#define LEETCODE_SWIMINRISINGWATER_HPP

#include <vector>
#include <queue>

using namespace std;

/// Min-Heap (Dijkstra-style): pop (max_elevation, r, c), push neighbors.
/// Time O(n^2 log n), Space O(n^2).
class Solution778Heap {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        // {max_elevation_along_path, row, col}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.emplace(grid[0][0], 0, 0);
        visited[0][0] = true;

        int dirs[] = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto [t, r, c] = pq.top();
            pq.pop();
            if (r == n - 1 && c == n - 1) return t;
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d], nc = c + dirs[d + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.emplace(max(t, grid[nr][nc]), nr, nc);
                }
            }
        }
        return -1; // unreachable
    }
};

/// Binary Search + BFS: binary search on t, BFS checking grid[nr][nc] <= t.
/// Time O(n^2 log n), Space O(n^2).
class Solution778BS {
public:
    int swimInWaterBS(vector<vector<int>>& grid) {
        int n = grid.size();
        int lo = grid[0][0], hi = n * n - 1;
        int dirs[] = {0, 1, 0, -1, 0};

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            // BFS to check if we can reach (n-1, n-1) with max elevation <= mid
            if (canReach(grid, n, mid, dirs)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

private:
    bool canReach(vector<vector<int>>& grid, int n, int t, int dirs[]) {
        if (grid[0][0] > t) return false;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (r == n - 1 && c == n - 1) return true;
            for (int d = 0; d < 4; d++) {
                int nr = r + dirs[d], nc = c + dirs[d + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc] && grid[nr][nc] <= t) {
                    visited[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }
        return false;
    }
};

#endif // LEETCODE_SWIMINRISINGWATER_HPP
