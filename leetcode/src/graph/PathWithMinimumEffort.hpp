#ifndef LEETCODE_PATHWITHMINIMUMEFFORT_HPP
#define LEETCODE_PATHWITHMINIMUMEFFORT_HPP

#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

// LeetCode 1631 - Path With Minimum Effort
class Solution1631 {
public:
    // Solution 1: Dijkstra's algorithm
    // O(m*n*log(m*n)) time, O(m*n) space
    static int dijkstra(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        if (rows == 1 && cols == 1) return 0;

        // 4 directions: up, down, left, right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // dist[r][c] = minimum effort to reach cell (r, c)
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        // Priority queue: (effort, row, col)
        using State = tuple<int, int, int>;
        priority_queue<State, vector<State>, greater<State>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();

            // Reached destination
            if (r == rows - 1 && c == cols - 1) return effort;

            // Skip if we already found a better path
            if (effort > dist[r][c]) continue;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;

                // New effort is the max of current effort and edge cost
                int newEffort = max(effort, abs(heights[nr][nc] - heights[r][c]));

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return dist[rows - 1][cols - 1];
    }

    // Solution 2: Binary search + BFS
    // O(m*n*log(max_height)) time, O(m*n) space
    static int binarySearch(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        if (rows == 1 && cols == 1) return 0;

        // Binary search on the answer [0, 1e6]
        int left = 0, right = 1000000;
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canReach(heights, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    // BFS to check if we can reach destination with max effort <= maxEffort
    static bool canReach(vector<vector<int>>& heights, int maxEffort) {
        int rows = heights.size();
        int cols = heights[0].size();

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == rows - 1 && c == cols - 1) return true;

            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                if (visited[nr][nc]) continue;

                int effort = abs(heights[nr][nc] - heights[r][c]);
                if (effort <= maxEffort) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }
};

#endif //LEETCODE_PATHWITHMINIMUMEFFORT_HPP
