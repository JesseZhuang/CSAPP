#ifndef LEETCODE_LONGESTPALINDROMICSUBSEQUENCE_HPP
#define LEETCODE_LONGESTPALINDROMICSUBSEQUENCE_HPP

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LongestPalindromicSubsequence {
public:
    // 2D DP approach
    // Time: O(n^2), Space: O(n^2)
    static int longestPalindromeSubseq(const string& s) {
        int n = s.size();
        // dp[i][j] = length of longest palindromic subsequence in s[i..j]
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case: single characters are palindromes of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Fill table for increasing lengths
        // Time: O(n^2) — two nested loops over substring length and start index
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }

    // 1D DP (space-optimized) approach
    // Time: O(n^2), Space: O(n)
    static int longestPalindromeSubseqOptimized(const string& s) {
        int n = s.size();
        // dp[j] represents the LPS length for the current row i to j
        vector<int> dp(n, 0);

        // Process from bottom-right to top-left
        // Time: O(n^2) — two nested loops
        // Space: O(n) — single array reused per row
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1; // dp[i][i] = 1
            int prev = 0; // stores dp[i+1][j-1]
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j]; // save dp[i+1][j] before overwrite
                if (s[i] == s[j]) {
                    dp[j] = prev + 2;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }
                prev = temp;
            }
        }

        return dp[n - 1];
    }
};

#endif // LEETCODE_LONGESTPALINDROMICSUBSEQUENCE_HPP
