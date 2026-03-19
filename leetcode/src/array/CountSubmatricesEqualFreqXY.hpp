#ifndef LEETCODE_COUNTSUBMATRICESEQUALFREQXY_HPP
#define LEETCODE_COUNTSUBMATRICESEQUALFREQXY_HPP

#include <vector>

using namespace std;

class CountSubmatricesEqualFreqXY {
public:
    // 15ms, 101.15Mb.
    int numberOfSubmatrices(vector<vector<char>> &grid) {
        const int m = static_cast<int>(grid.size());
        const int n = static_cast<int>(grid[0].size());
        int res = 0;
        vector<int> col_x(n, 0), col_y(n, 0);
        for (int i = 0; i < m; ++i) {
            int row_x = 0, row_y = 0;
            for (int j = 0; j < n; ++j) {
                col_x[j] += (grid[i][j] == 'X');
                col_y[j] += (grid[i][j] == 'Y');
                row_x += col_x[j];
                row_y += col_y[j];
                if (row_x == row_y && row_x > 0) {
                    ++res;
                }
            }
        }
        return res;
    }
};

#endif // LEETCODE_COUNTSUBMATRICESEQUALFREQXY_HPP
