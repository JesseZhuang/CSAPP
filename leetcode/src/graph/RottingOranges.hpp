#ifndef LEETCODE_ROTTINGORANGES_HPP
#define LEETCODE_ROTTINGORANGES_HPP

#include <vector>
#include <queue>

using namespace std;

// leet 994
class Solution994 {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, res = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        int dirs[][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty() && fresh > 0) {
            res++;
            for (int sz = q.size(); sz > 0; sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto &d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (grid[nx][ny] != 1) continue;
                    fresh--;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                }
            }
        }
        return fresh == 0 ? res : -1;
    }
};

#endif //LEETCODE_ROTTINGORANGES_HPP
