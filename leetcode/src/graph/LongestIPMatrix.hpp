#ifndef LEETCODE_LONGESTIPMATRIX_HPP
#define LEETCODE_LONGESTIPMATRIX_HPP

#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> cache(n, vector<int>(m, 0));
        int dirs[4][2] = {{0,  1},
                          {0,  -1},
                          {1,  0},
                          {-1, 0}};
        function<int(int, int)> dfs = [&](int r, int c) {
            if (cache[r][c] != 0) return cache[r][c];
            int res = 0;
            for (auto [dr, dc]: dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nr > n - 1 || nc < 0 || nc > m - 1 || matrix[nr][nc] <= matrix[r][c]) continue;
                res = max(res, dfs(nr, nc));
            }
            res++;
            cache[r][c] = res;
            return res;
        };
        int res = 0;
        for (int r = 0; r < n; r++)
            for (int c = 0; c < m; c++)
                res = max(res, dfs(r, c));
        return res;
    }
};

#endif //LEETCODE_LONGESTIPMATRIX_HPP
