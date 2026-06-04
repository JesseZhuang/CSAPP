#ifndef LONGESTCOMMONSUBSEQUENCE_HPP
#define LONGESTCOMMONSUBSEQUENCE_HPP
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 1D DP. O(m*n) time, O(min(m,n)) space.
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        if (m < n) return longestCommonSubsequence(text2, text1);
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < m; i++) { // O(m)
            int pr = 0, prpc;
            for (int j = 0; j < n; j++) { // O(n)
                prpc = pr;
                pr = dp[j + 1];
                dp[j + 1] = text1[i] == text2[j] ? prpc + 1 : max(dp[j], pr);
            }
        }
        return dp[n];
    }
};

class Solution2D {
public:
    // 2D DP. O(m*n) time, O(m*n) space.
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // O(m*n) space
        for (int i = 0; i < m; i++) // O(m)
            for (int j = 0; j < n; j++) // O(n)
                dp[i + 1][j + 1] = text1[i] == text2[j]
                    ? dp[i][j] + 1
                    : max(dp[i][j + 1], dp[i + 1][j]);
        return dp[m][n];
    }
};

#endif
