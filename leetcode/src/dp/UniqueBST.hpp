#ifndef UNIQUEBST_HPP
#define UNIQUEBST_HPP
#include <vector>

using namespace std;

// solution 1, bottom-up DP (Catalan recurrence). O(n^2) time, O(n) space.
// G(n) = sum_{i=1..n} G(i-1) * G(n-i), G(0) = 1.
class UniqueBSTDP {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) // O(n)
            for (int j = 1; j <= i; j++) // O(n)
                dp[i] += dp[j - 1] * dp[i - j];
        return dp[n];
    }
};

// solution 2, direct Catalan formula. O(n) time, O(1) space.
// C(n) = C(2n, n) / (n+1) = product_{i=0..n-1} (2n-i) / (i+1)
class UniqueBSTCatalan {
public:
    int numTrees(int n) {
        long long result = 1;
        for (int i = 0; i < n; i++) {
            result = result * (2 * n - i) / (i + 1);
        }
        return static_cast<int>(result / (n + 1));
    }
};

#endif //UNIQUEBST_HPP
