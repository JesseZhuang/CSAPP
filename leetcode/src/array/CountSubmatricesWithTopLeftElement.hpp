#ifndef LEETCODE_COUNTSUBMATRICESWITHTOPLEFTELEMENT_HPP
#define LEETCODE_COUNTSUBMATRICESWITHTOPLEFTELEMENT_HPP

#include <vector>

using namespace std;

class Solution {
public:
    // 6ms, 91.18Mb.
    int resSubmatrices(vector<vector<int>> &grid, int k) {
        int res = 0;
        int m = static_cast<int>(grid.size()), n = static_cast<int>(grid[0].size());
        vector<int> col_sum(n);
        for (int i = 0; i < m; ++i) {
            long long row_sum = 0;
            for (int j = 0; j < n; ++j) {
                col_sum[j] += grid[i][j];
                row_sum += col_sum[j];
                if (row_sum <= k) {
                    ++res;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};

#endif // LEETCODE_COUNTSUBMATRICESWITHTOPLEFTELEMENT_HPP
