#ifndef LEETCODE_ZEROONEMATRIX_HPP
#define LEETCODE_ZEROONEMATRIX_HPP

#include <vector>
#include <algorithm>

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

#endif //LEETCODE_ZEROONEMATRIX_HPP
