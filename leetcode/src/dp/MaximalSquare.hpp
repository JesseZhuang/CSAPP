#ifndef MAXIMALSQUARE_HPP
#define MAXIMALSQUARE_HPP
#include <algorithm>
#include <vector>

using namespace std;

// LeetCode 221. Maximal Square
// DP: dp[j] = side length of largest square with bottom-right at (i,j).
// Transition: dp[j] = min(dp[j-1], prev_dp[j], prev_dp[j-1]) + 1 if matrix[i][j] == '1'.
// O(m*n) time, O(n) space.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n, 0);
        int maxSide = 0;
        for (int i = 0; i < m; i++) {
            vector<int> prev_dp = dp;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0)
                        dp[j] = 1;
                    else
                        dp[j] = min({prev_dp[j], dp[j - 1], prev_dp[j - 1]}) + 1;
                    maxSide = max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }
            }
        }
        return maxSide * maxSide;
    }
};

#endif
