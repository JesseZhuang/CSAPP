#ifndef LEETCODE_ZEROONEMATRIX_HPP
#define LEETCODE_ZEROONEMATRIX_HPP

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// leet 542, DP. O(m*n) time, O(1) space (in-place).
class Solution542 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int INF = m + n;
        // top-left to bottom-right
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] > 0) {
                    int top = r > 0 ? mat[r - 1][c] : INF;
                    int left = c > 0 ? mat[r][c - 1] : INF;
                    mat[r][c] = min(top, left) + 1;
                }
            }
        }
        // bottom-right to top-left
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (mat[r][c] > 0) {
                    int bottom = r < m - 1 ? mat[r + 1][c] : INF;
                    int right = c < n - 1 ? mat[r][c + 1] : INF;
                    mat[r][c] = min(mat[r][c], min(bottom + 1, right + 1));
                }
            }
        }
        return mat;
    }
};

// leet 542, multi-source BFS. O(m*n) time, O(m*n) space.
class Solution542BFS {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0)
                    q.push({r, c});
                else
                    mat[r][c] = -1;
            }
        }
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && mat[nr][nc] == -1) {
                    mat[nr][nc] = mat[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
        return mat;
    }
};

#endif //LEETCODE_ZEROONEMATRIX_HPP
