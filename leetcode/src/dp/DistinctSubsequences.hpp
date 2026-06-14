#ifndef DISTINCTSUBSEQUENCES_HPP
#define DISTINCTSUBSEQUENCES_HPP
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 1D DP (space optimized). O(m*n) time, O(n) space.
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1; // empty t is a subsequence of any prefix of s

        // O(m*n): for each char in s, update dp in reverse
        for (int i = 1; i <= m; i++) {
            // traverse j in reverse to avoid using updated values
            for (int j = min(i, n); j >= 1; j--) { // O(n) per iteration
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return static_cast<int>(dp[n]);
    }
};

class Solution2D {
public:
    // 2D DP. O(m*n) time, O(m*n) space.
    // dp[i][j] = number of distinct subsequences of s[0:i] that equal t[0:j]
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        if (m < n) return 0;
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        // Base case: empty t can be formed from any prefix of s in exactly 1 way
        for (int i = 0; i <= m; i++) dp[i][0] = 1;

        // O(m*n): fill table row by row
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) { // O(n) per row
                dp[i][j] = dp[i - 1][j]; // skip s[i-1]
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] += dp[i - 1][j - 1]; // use s[i-1] to match t[j-1]
                }
            }
        }
        return static_cast<int>(dp[m][n]);
    }
};

#endif
