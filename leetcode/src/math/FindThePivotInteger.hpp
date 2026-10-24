#ifndef LEETCODE_FINDTHEPIVOTINTEGER_HPP
#define LEETCODE_FINDTHEPIVOTINTEGER_HPP

#include <cmath>

class Solution {
public:
    // O(1) time, O(1) space: the pivot squared equals the total sum.
    int pivotInteger(int n) {
        long long total = 1LL * n * (n + 1LL) / 2;
        long long pivot = static_cast<long long>(std::sqrt(total));
        return pivot * pivot == total ? static_cast<int>(pivot) : -1;
    }

    // O(n) time, O(1) space: track the sums on both sides of each pivot.
    int pivotIntegerPrefixSum(int n) {
        long long prefix = 0;
        long long suffix = 1LL * n * (n + 1LL) / 2;
        for (int value = 1; value <= n; ++value) { // O(n) iterations
            prefix += value;
            if (prefix == suffix) return value;
            suffix -= value;
        }
        return -1;
    }
};

#endif
