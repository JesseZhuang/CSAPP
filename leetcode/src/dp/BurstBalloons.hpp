#ifndef BURSTBALLOONS_HPP
#define BURSTBALLOONS_HPP
#include <vector>
#include <algorithm>

using namespace std;

// LeetCode 312: Burst Balloons
// Bottom-up interval DP solution
// Time: O(n^3), Space: O(n^2)
// dp[i][j] = max coins from bursting all balloons between i and j (exclusive)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // Pad with 1s on both ends
        vector<int> balloons(n + 2);
        balloons[0] = 1;
        balloons[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }

        // dp[i][j] = max coins bursting all balloons between i and j (exclusive)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Iterate by interval length
        for (int len = 1; len <= n; len++) {
            // Iterate by left endpoint
            for (int i = 0; i + len + 1 < n + 2; i++) {
                int j = i + len + 1;
                // Try each balloon k as the last one to burst in (i, j)
                for (int k = i + 1; k < j; k++) {
                    // When k is the last to burst, left and right are still there
                    int coins = balloons[i] * balloons[k] * balloons[j];
                    coins += dp[i][k] + dp[k][j];
                    dp[i][j] = max(dp[i][j], coins);
                }
            }
        }

        return dp[0][n + 1];
    }
};

#endif //BURSTBALLOONS_HPP
