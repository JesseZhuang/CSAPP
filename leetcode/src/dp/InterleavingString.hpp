#pragma once
#include <string>
#include <vector>

using namespace std;

class InterleavingSolution {
public:
    // 1D DP. O(mn) time, O(n) space.
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != (int)s3.size()) return false;
        vector<bool> dp(n + 1, false);
        // O(n) — initialize first row
        for (int j = 0; j <= n; j++) {
            dp[j] = (j == 0) || (dp[j - 1] && s2[j - 1] == s3[j - 1]);
        }
        // O(m*n) — fill row by row
        for (int i = 1; i <= m; i++) {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j <= n; j++) { // O(n) per row
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                         (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[n];
    }
};

class InterleavingSolution2D {
public:
    // 2D DP. O(mn) time, O(mn) space.
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != (int)s3.size()) return false;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        // O(m) — initialize first column
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        // O(n) — initialize first row
        for (int j = 1; j <= n; j++) {
            dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }
        // O(m*n) — fill table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) { // O(n) per row
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                            (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
};
