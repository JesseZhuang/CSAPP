#ifndef LEETCODE_COUNTWAYSGOODSTRINGS_HPP
#define LEETCODE_COUNTWAYSGOODSTRINGS_HPP

#include <vector>

using namespace std;

// leet 2466, O(high) time and space.
class CountWaysGoodStrings {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int mod = 1e9 + 7;
        vector<long> dp(high + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) dp[i] += dp[i - zero];
            if (i >= one) dp[i] += dp[i - one];
            dp[i] %= mod;
        }
        long res = 0;
        for (int i = low; i <= high; i++) res += dp[i];
        return (int) (res % mod);
    }
};

#endif //LEETCODE_COUNTWAYSGOODSTRINGS_HPP
