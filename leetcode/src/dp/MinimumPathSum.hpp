#ifndef MINIMUMPATHSUM_HPP
#define MINIMUMPATHSUM_HPP

#include <vector>
#include <algorithm>

using namespace std;

// solution 1, in-place DP. O(m*n) time, O(1) extra space.
class MinimumPathSumDP {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] += grid[i][j - 1];
                else if (j == 0) grid[i][j] += grid[i - 1][j];
                else grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[m - 1][n - 1];
    }
};

// solution 2, 1D DP. O(m*n) time, O(n) space.
class MinimumPathSum1D {
public:
    int minPathSum(const vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[j] = grid[0][0];
                else if (i == 0) dp[j] = dp[j - 1] + grid[i][j];
                else if (j == 0) dp[j] = dp[j] + grid[i][j];
                else dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};

#endif
